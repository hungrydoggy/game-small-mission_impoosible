#ifndef GAME_GAME_STATE_H_
#define GAME_GAME_STATE_H_

#include <appetizer.h>


using namespace appetizer;

struct GameState : public ObjectTrait, public IOnInitCallback {
public: // vars
  int round_no = 1;
  int score = 0;
  int hp     = 10;
  int max_hp = 10;
  int round_mole_count = 5;
  int activated_mole_count   = 0;
  int inactivated_mole_count = 0;
  vector<GameObject*> active_holes;


public: // methods
  ObjectTraitGroupIdType trait_group_id () const override;

  void setByRoundNo (int round_no);

  GameObject* pickInactiveMole ();

  GameObject* pickInactiveSnack ();

  GameObject* pickNextHammer ();

  GameObject* pickNextCoin ();

  double getMoleShowWaitDur ();

  double getMoleStealDur ();

  double getHammerBrokenDur ();

  void inactivateAll ();

  void printAll ();


private: // vars
  vector<GameObject*> moles_;
  vector<GameObject*> hedgehogs_;
  vector<GameObject*> snacks_;
  vector<GameObject*> hammers_;
  vector<GameObject*> coins_;

  int next_hammer_idx_;
  int next_coin_idx_;

private: // methods
  void onInit () override;
};


#endif
