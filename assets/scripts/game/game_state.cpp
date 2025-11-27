#include "./game_state.h"


StringRegistryIdType g_fsm_gid = StringRegistry::default_registry().lookUp("finite_state_machine");


StringRegistryIdType g_trait_group_id = StringRegistry::default_registry().lookUp("game_state");
ObjectTraitGroupIdType GameState::trait_group_id () const {
  return g_trait_group_id;
}


const double kRoundMoleCountMin = 5;
const double kRoundMoleCountMax = 100;

static int __getRoundMoleCount (int round_no) {
  auto t = math::min((round_no-1) / 98.0, 1.0);
  return (int)math::round((-(t-1)*(t-1) + 1) * (kRoundMoleCountMax - kRoundMoleCountMin) + kRoundMoleCountMin);
}


void GameState::setByRoundNo (int round_no) {
  this->round_no = round_no;
  this->round_mole_count = __getRoundMoleCount(round_no);
  this->activated_mole_count   = 0;
  this->inactivated_mole_count = 0;

  unlikely (round_no == 1) {
    this->score  = 0;
    this->hp     = 10;
    this->max_hp = 10;
  }

  auto holes = owner()->findByNamePath("/holes");

  auto hole_cnt = math::min(round_no + 1, 8);
  RandomPicker picker(8);

  active_holes.clear();
  for (int hi=0; hi<hole_cnt; ++hi) {
    auto idx = picker.pick();
    active_holes.push_back(holes->findChild<GameObject>(std::to_string(idx)).get());
  }
}


static GameObject* __pickInactiveElem (vector<GameObject*> const& vec) {
  RandomPicker picker(vec.size());
  int idx = 0;
  while ((idx = picker.pick()) >= 0) {
    auto obj = vec[idx];
    auto fsm = obj->getTrait<Fsm>(g_fsm_gid);
    likely (fsm->cur_state()->name() == "inactive")
      return obj;
  }

  return null;
}


const double kHedgehogAppearChanceMin = 0.10;
const double kHedgehogAppearChanceMax = 0.33;

static bool __needPickHedgehog (int round_no) {
  auto t = math::min((round_no-1) / 98.0, 1.0);
  auto v = ((-(t-1)*(t-1) + 1) * (kHedgehogAppearChanceMax - kHedgehogAppearChanceMin) + kHedgehogAppearChanceMin);
  return DefaultRandomPocket::draw(0.0, 1.0) <= v;
}


GameObject* GameState::pickInactiveMole () {
  unlikely (__needPickHedgehog(round_no) == true)
    return __pickInactiveElem(hedgehogs_);
  else
    return __pickInactiveElem(moles_);
}


GameObject* GameState::pickInactiveSnack () {
  return __pickInactiveElem(snacks_);
}


GameObject* GameState::pickNextHammer () {
  auto next = hammers_[next_hammer_idx_];
  next_hammer_idx_ = (next_hammer_idx_ + 1) % hammers_.size();
  return next;
}


GameObject* GameState::pickNextCoin () {
  auto next = coins_[next_coin_idx_];
  next_coin_idx_ = (next_coin_idx_ + 1) % coins_.size();
  return next;
}


const double kMoleShowWaitDurMin = 0.5;
const double kMoleShowWaitDurMax = 4;

double GameState::getMoleShowWaitDur () {
  auto ratio = math::min((round_no-1) / 98.0, 1.0) * -0.9 + 1.0;

  return DefaultRandomPocket::draw(
      kMoleShowWaitDurMin * ratio,
      kMoleShowWaitDurMax * ratio
  );
}


const double kMoleStealDurMin = 0.3;
const double kMoleStealDurMax = 1.7;

double GameState::getMoleStealDur () {
  auto t = math::min((round_no-1) / 98.0, 1.0);
  return ((t-1)*(t-1)*(t-1) + 1) * -(kMoleStealDurMax - kMoleStealDurMin) + kMoleStealDurMax;
}


const double kHammerBrokenDurMin = 1.0;
const double kHammerBrokenDurMax = 2.0;

double GameState::getHammerBrokenDur () {
  auto t = math::min((round_no-1) / 98.0, 1.0);
  return t*t * -(kHammerBrokenDurMax - kHammerBrokenDurMin) + kHammerBrokenDurMax;
}


static void __inactiveElems (vector<GameObject*> const& elements, string const& as_path) {
  for (auto e : elements) {
    e->is_drawable_self(false);
    auto fsm = e->getTrait<Fsm>(g_fsm_gid);
    e->findByNamePath<GameObject>(as_path)->setAction(null, "");
    fsm->setCurState("inactive");
  }
}


void GameState::inactivateAll () {
  for (auto h : active_holes) {
    h->setData("is_active", false);

    unlikely (h->is_drawable_self() == true)
      h->setAction("hide");
  }

  __inactiveElems(moles_    , "img");
  __inactiveElems(hedgehogs_, "img");
  __inactiveElems(snacks_   , "."  );

}


static void __printElements (vector<GameObject*> const& elements, bool has_is_active_data, bool has_fsm) {
  for (size_t ei=0; ei<elements.size(); ++ei) {
    auto e = elements[ei];
    cout << "  [" << ei << "]:" << endl;
    cout << "    is_drawable_self: " << e->is_drawable_self() << endl;
    unlikely (has_is_active_data == true)
      cout << "    is_active data: " << e->getData("is_active", false) << endl;
    unlikely (has_fsm == true)
      cout << "    fsm state name: " << e->getTrait<Fsm>(g_fsm_gid)->cur_state()->name() << endl;
  }
}


void GameState::printAll () {
  cout
      << "round_no: " <<  round_no << endl
      << "score: " << score << endl
      << "hp: " << hp << endl
      << "max_hp: " << max_hp << endl
      << "round_mole_count: " << round_mole_count << endl
      << "activated_mole_count: " << activated_mole_count << endl
      << "inactivated_mole_count: " << inactivated_mole_count << endl;

  cout << "active_holes:" << endl;
  __printElements(active_holes, true, false);

  cout << "moles:" << endl;
  __printElements(moles_, false, true);

  cout << "snacks:" << endl;
  __printElements(snacks_, false, true);

  cout << "hammers:" << endl;
  __printElements(hammers_, false, false);

  cout << "coins:" << endl;
  __printElements(coins_, false, false);

  cout << "next_hammer_idx: " <<  next_hammer_idx_ << endl;
  cout << "next_coin_idx: " <<  next_coin_idx_ << endl;
}


static void __fillChildObjs (vector<GameObject*>& vec, GameComponent* owner, string const& parent_path) {

  vec.clear();

  auto parent = owner->findByNamePath(parent_path);
  for (auto& c : parent->children()) {
    auto obj = dynamic_cast<GameObject*>(c.get());
    likely (obj != null)
      vec.push_back(obj);
  }
}


void GameState::onInit () {

  __fillChildObjs(moles_    , owner(), "/moles"    );
  __fillChildObjs(hedgehogs_, owner(), "/hedgehogs");
  __fillChildObjs(snacks_   , owner(), "/snacks"   );
  __fillChildObjs(hammers_  , owner(), "/hammers"  );
  __fillChildObjs(coins_    , owner(), "/coins"    );

  next_hammer_idx_ = 0;
  next_coin_idx_   = 0;
}
