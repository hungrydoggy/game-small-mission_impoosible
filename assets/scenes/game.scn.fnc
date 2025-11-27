%Envelope%:

  include_part:
    '''{
      #include <algorithm>
      #include <filesystem>

      #include "scripts/common/rank_item.h"
    '''

  neck_part:
    '''{
      using namespace appetizer;

      using std::to_string;
      namespace fs = std::filesystem;


      enum class PlayState {
        READY_TO_START,
        PLAYING,
        PAUSED,
        DEAD,
      };


      struct BoardCoord {
        int x = 0;
        int y = 0;
      };

      enum class SnakeActionType {
        TURN_LEFT,
        TURN_RIGHT,
        EAT_APPLE,
        EAT_BANANA,
      };

      struct SnakeAction {
        SnakeActionType type;
        BoardCoord pos;
      };


      struct GameData;


      struct GameState {
        PlayState play_state;

        byte board_w = 10;
        byte board_h = 10;
        bool need_tile_show_action = false;

        int level = 1;
        int apple_left = 1;
        int score = 0;

        double snake_speed_spt     = 1.0;  // spt means second per tile
        double snake_acc_spt       = 1.5;
        double snake_min_speed_spt = 0.25;

        byte snake_length = 2;
        BoardCoord snake_head_pos;
        BoardCoord snake_velocity;
        vector<SnakeAction> snake_action_history;

        vector<BoardCoord> wall_poses;

        BoardCoord apple_pos;
        BoardCoord banana_pos;


        sp<fun_tree::Content> convertToMap ();
        void setByMap (sp<fun_tree::Content> const& map);

        int getSnakeDirIdx () {
          // up, right, down, left
          return
              ((snake_velocity.x == 0)? 0 : (3 - (snake_velocity.x + 1)))
              + ((snake_velocity.y == 0)? 0 : (2 - (snake_velocity.y + 1)));
        }

        bool isOnBoard (BoardCoord const& pos) {
          return pos.x >= 0 && pos.x < board_w && pos.y >= 0 && pos.y < board_h;
        }

        bool isOnWall (BoardCoord const& pos);

        void speedUp (GameData* gd);

        void levelUp ();
      };


      struct GameData {
        real tile_w = REAL(40.0);

        KeyEventType last_key_type;

        GameObject*    ui_level_cmp;
        GameObject*    ui_score_cmp;
        GameComponent* ui_press_any_key_to_start_cmp;

        GameComponent* tiles_cmp;
        vector<GameObject*> tiles;

        GameComponent* walls_cmp;
        vector<GameComponent*> walls;

        GameComponent* snake_face_cmp;

        GameComponent* snake_body_cmp;
        vector<GameComponent*> snake_bodies;

        vector<BoardCoord> snake_body_poses;

        GameObject* apple_cmp;
        GameObject* banana_cmp;

        vector<GameObject*> blings;
        int next_bling_idx = 0;

        double elapsed_time;
        int await_action_count;


        void processInput (GameState* gs);

        void updateSnake (GameState* gs);

        bool isOnBody (BoardCoord const& pos, bool skip_tail=false);

        void placeApple (Scene* scene, GameState* gs);
        void placeBanana (Scene* scene, GameState* gs);
      };


      static auto action_state_gid = StringRegistry::default_registry().lookUp("action_state");
    '''

  val:
    '%onInit':
      '''{(NodeLoadable* loadable)
        auto self = loadable->cast<Scene>();

        auto gs = make_shared<GameState>();
        self->setData("game_state", gs);

        auto gd = make_shared<GameData>();
        self->setData("game_data", gd);


        // game state
        gs->board_w             = self->getData("board_w"            , 10);
        gs->board_h             = self->getData("board_h"            , 10);
        gs->snake_speed_spt     = self->getData("snake_speed_spt"    , 1.0);
        gs->snake_acc_spt       = self->getData("snake_acc_spt"      , 1.5);
        gs->snake_min_speed_spt = self->getData("snake_min_speed_spt", 1.0);


        // game data
        gd->tile_w = self->getData("tile_w", REAL(40.0));

        gd->ui_level_cmp                  = self->findByNamePath<GameObject>("./*/ui/level");
        gd->ui_score_cmp                  = self->findByNamePath<GameObject>("./*/ui/score");
        gd->ui_press_any_key_to_start_cmp = self->findByNamePath<GameObject>("./*/ui/press_any_key_to_start");

        gd->tiles_cmp = self->findByNamePath("./tiles");
        gd->tiles.clear();
        for (int ci=0; ci<gd->tiles_cmp->getChildCount(); ++ci) {
          auto t = gd->tiles_cmp->getChild<GameObject>(ci);
          likely (t != null)
            gd->tiles.push_back(t.get());
        }

        gd->walls_cmp = self->findByNamePath("./walls");
        gd->walls.clear();
        for (int ci=0; ci<gd->walls_cmp->getChildCount(); ++ci) {
          auto w = gd->walls_cmp->getChild(ci);
          likely (w != null)
            gd->walls.push_back(w.get());
        }

        gd->snake_face_cmp = self->findByNamePath("./snake/face");

        gd->snake_body_cmp = self->findByNamePath("./snake/body");
        gd->snake_bodies.clear();
        for (int ci=0; ci<gd->snake_body_cmp->getChildCount(); ++ci) {
          auto t = gd->snake_body_cmp->getChild(ci);
          likely (t != null)
            gd->snake_bodies.push_back(t.get());
        }

        gd->apple_cmp  = self->findByNamePath<GameObject>("./fruit/apple" );
        gd->banana_cmp = self->findByNamePath<GameObject>("./fruit/banana");

        auto blings = self->findByNamePath("./blings");
        for (int ci=0; ci<blings->getChildCount(); ++ci) {
          auto b = blings->getChild<GameObject>(ci);
          likely (b != null)
            gd->blings.push_back(b.get());
        }

        gd->snake_body_poses.clear();

        gd->await_action_count = 0;


        self->callFunc("resetGame", {});
      '''

    '%onSaveState':
      '''{(NodeLoadable* loadable)
        auto self = loadable->cast<Scene>();

        auto& gs = self->getDataRef("game_state").v<sp<GameState>>();
        auto content = gs->convertToMap();

        return Var(content);
      '''

    '%onRestoreState':
      '''{(NodeLoadable* loadable, sp<Content> state_content)
        auto self = loadable->cast<Scene>();

        auto& gs = self->getDataRef("game_state").v<sp<GameState>>();
        gs->setByMap(state_content);

      '''

    '%onUpdate':
      '''{(NodeLoadable* loadable, double delta_time)
        auto self = loadable->cast<Scene>();

        auto& gs = self->getDataRef("game_state").v<sp<GameState>>();
        auto& gd = self->getDataRef("game_data" ).v<sp<GameData >>();

        unlikely (gs->play_state != PlayState::PLAYING)
          return null_var;


        gd->processInput(gs.get());


        // update snake pos
        gd->elapsed_time += delta_time;
        bool snake_moved = false;
        while (gd->elapsed_time > gs->snake_speed_spt) {

          gs->snake_head_pos.x += gs->snake_velocity.x;
          gs->snake_head_pos.y += gs->snake_velocity.y;


          // check dead
          auto is_on_board = gs->isOnBoard(gs->snake_head_pos);
          auto is_on_wall  = gs->isOnWall (gs->snake_head_pos);
          auto is_on_body  = gd->isOnBody (gs->snake_head_pos, true);
          unlikely (is_on_board == false || is_on_wall == true || is_on_body == true) {
            gd->snake_face_cmp->callFunc("select", {Var("unhappy")});

            auto result_popup = self->findByNamePath("./*/ui/popup.result");
            likely (result_popup != null) {
              result_popup->callFunc("setLevelScore", {Var(gs->level), Var(gs->score)});
              result_popup->callFunc("setRank", {Var((vector<RankItem>*)null), Var(-1)});
              self->callFunc("refreshRank", {Var(""), Var(gs->score)});
            }

            auto state_obj = self->findByNamePath<GameObject>("./state_obj");
            likely (state_obj != null)
              state_obj->setAction("onDead");
            gs->play_state = PlayState::DEAD;
            return null_var;
          }


          // turn
          likely (gs->snake_action_history.size() > 0) {
            auto& last_action = gs->snake_action_history.back();
            auto hit_act = last_action.pos.x == gs->snake_head_pos.x && last_action.pos.y == gs->snake_head_pos.y;
            unlikely (hit_act == true) {
              auto& vel = gs->snake_velocity;
              switch (last_action.type) {
                case SnakeActionType::TURN_LEFT:
                  vel = (vel.x == 0)? BoardCoord{-vel.y, 0}: BoardCoord{0, vel.x};
                  break;
                case SnakeActionType::TURN_RIGHT:
                  vel = (vel.x == 0)? BoardCoord{vel.y, 0}: BoardCoord{0, -vel.x};
                  break;
              }
              gd->await_action_count = 0;
            }
          }


          // eating apple
          auto eating_apple = gs->snake_head_pos.x == gs->apple_pos.x && gs->snake_head_pos.y == gs->apple_pos.y;
          unlikely (eating_apple == true) {
            gs->snake_action_history.push_back({
                SnakeActionType::EAT_APPLE,
                gs->apple_pos,
            });
            gs->snake_length += 1;
            gs->speedUp(gd.get());
            gs->apple_left -= 1;
            gs->apple_pos = {-1, -1};
            gd->apple_cmp->is_drawable_self(false);
            self->callFunc("showBlingEffect", {Var(gd->apple_cmp->x()), Var(gd->apple_cmp->y())});

            unlikely (gs->apple_left > 0)
              gd->placeApple(self, gs.get());
            else
              gd->placeBanana(self, gs.get());

            gs->score += 10;
            self->callFunc("updateUi", {});
          }

          // eating banana
          auto eating_banana = gs->snake_head_pos.x == gs->banana_pos.x && gs->snake_head_pos.y == gs->banana_pos.y;
          unlikely (eating_banana == true) {
            gs->snake_action_history.push_back({
                SnakeActionType::EAT_BANANA,
                gs->banana_pos,
            });
            gs->speedUp(gd.get());
            gs->levelUp();
            gs->banana_pos = {-1, -1};
            gd->banana_cmp->is_drawable_self(false);
            self->callFunc("showBlingEffect", {Var(gd->banana_cmp->x()), Var(gd->banana_cmp->y())});

            gs->score += 100;
            self->callFunc("applyGameState", {});
            self->callFunc("updateUi", {});
            gd->updateSnake(gs.get());
            gd->placeApple(self, gs.get());
          }


          snake_moved = true;
          gd->elapsed_time -= gs->snake_speed_spt;
        }

        gd->updateSnake(gs.get());


      '''

    '%onKeyInput':
      '''{(NodeLoadable* loadable, KeyEvent const* e)
        auto self = loadable->cast<Scene>();

        auto& gs = self->getDataRef("game_state").v<sp<GameState>>();
        auto& gd = self->getDataRef("game_data" ).v<sp<GameData >>();

        unlikely (e->state != KeyEventState::STATE_PRESSED)
          return null_var;

        switch (gs->play_state) {
          case PlayState::READY_TO_START:
            gs->play_state = PlayState::PLAYING;
            self->callFunc("updateUi", {});
            break;

          //case PlayState::DEAD:
          //  unlikely (e->type == KeyEventType::KEY_ENTER)
          //    self->callFunc("resetGame", {});
          //  return null_var;

          default:
            break;
        }


        gd->last_key_type = e->type;

      '''

    '~onTabPane':
      '''{(Scene* self, ,,, vector<Var> msg_params)
        auto& world_pos = msg_params[0].v<Vector3>();

        auto& gd = self->getDataRef("game_data" ).v<sp<GameData >>();

        auto face = gd->snake_face_cmp;
        auto snake_pos = self->inv_base_matrix() * face->base_matrix() * face->model_matrix() * Vector3::kZero;;

        auto angle = Vector2::computeAngle(Vector2(-1, 1), Vector2(world_pos) - Vector2(snake_pos));
        auto dir_idx = (int)(angle/(math::kPI * REAL(0.5)) + REAL(2.0));

        switch (dir_idx) {
          case 0: // right
            Project::active_project()->enqueueKeyEvent({KeyEventType::KEY_RIGHT, KeyEventState::STATE_PRESSED});
            break;
          case 1: // up
            Project::active_project()->enqueueKeyEvent({KeyEventType::KEY_UP, KeyEventState::STATE_PRESSED});
            break;
          case 2: // left
            Project::active_project()->enqueueKeyEvent({KeyEventType::KEY_LEFT, KeyEventState::STATE_PRESSED});
            break;
          case 3: // down
            Project::active_project()->enqueueKeyEvent({KeyEventType::KEY_DOWN, KeyEventState::STATE_PRESSED});
            break;
        }
      '''

    'resetGame':
      '''{(NodeLoadable* loadable)
        auto self = loadable->cast<Scene>();

        auto& gs = self->getDataRef("game_state").v<sp<GameState>>();
        auto& gd = self->getDataRef("game_data" ).v<sp<GameData >>();

        gs->play_state = PlayState::READY_TO_START;

        gs->level      = 1;
        gs->apple_left = 1;
        gs->score      = 0;

        gs->board_w         = self->getData("board_w"        , 10);
        gs->board_h         = self->getData("board_h"        , 10);
        gs->snake_speed_spt = self->getData("snake_speed_spt", 1.0);

        gs->need_tile_show_action = false;

        gs->wall_poses.clear();

        gs->snake_length = 2;
        gs->snake_head_pos = {1, (byte)gs->board_h/2};
        gs->snake_velocity = {1, 0};
        gs->snake_action_history.clear();
        gs->apple_pos  = {-1, -1};
        gs->banana_pos = {-1, -1};

        gd->next_bling_idx = 0;
        gd->last_key_type = KeyEventType::KEY_NONE;
        gd->elapsed_time = 0.0;

        self->callFunc("applyGameState", {});

        gd->apple_cmp ->is_drawable_self(false);
        gd->banana_cmp->is_drawable_self(false);
        gd->placeApple(self, gs.get());
        gd->updateSnake(gs.get());
      '''

    'applyGameState':
      '''{(NodeLoadable* loadable)
        auto self = loadable->cast<Scene>();

        auto& gs = self->getDataRef("game_state").v<sp<GameState>>();
        auto& gd = self->getDataRef("game_data" ).v<sp<GameData >>();


        // apply tiles
        for (auto& t : gd->tiles)
          t->is_drawable_self(false);

        for (byte y=0; y<gs->board_h; ++y) {
          for (byte x=0; x<gs->board_w; ++x) {
            byte idx = y * gs->board_w + x;
            auto t = gd->tiles[idx];
            t->callFunc("select", {Var(to_string(((x%2) + (y%2))%2))});
            t->position({
                (x - (gs->board_w - 1) * REAL(0.5)) * gd->tile_w,
                (y - (gs->board_h - 1) * REAL(0.5)) * gd->tile_w,
                REAL(0.0)
            });

            auto is_on_edge = x == 0 || y == 0 || x == gs->board_w-1 || y == gs->board_h-1;
            likely (gs->need_tile_show_action == false || is_on_edge == false)
              t->is_drawable_self(true);
            else
              t->setAction("show");
          }
        }


        // apply walls
        for (auto& w : gd->walls)
          w->is_drawable_self(false);

        for (size_t wi=0; wi<gs->wall_poses.size(); ++wi) {
          auto& wp = gs->wall_poses[wi];
          auto& w = gd->walls[wi];
          w->position({
              (wp.x - (gs->board_w - 1) * REAL(0.5)) * gd->tile_w,
              (wp.y - (gs->board_h - 1) * REAL(0.5)) * gd->tile_w,
              REAL(0.0)
          });
          w->is_drawable_self(true);
        }


        // update ui
        self->callFunc("updateUi", {});
      '''

    'updateUi':
      '''{(NodeLoadable* loadable)
        auto self = loadable->cast<Scene>();

        auto& gs = self->getDataRef("game_state").v<sp<GameState>>();
        auto& gd = self->getDataRef("game_data" ).v<sp<GameData >>();

        gd->ui_level_cmp->setText("Level: " + to_string(gs->level));
        gd->ui_score_cmp->setText("Score: " + to_string(gs->score));
        gd->ui_press_any_key_to_start_cmp->is_drawable_self(gs->play_state == PlayState::READY_TO_START);
      '''

    'refreshRank':
      '''{(NodeLoadable* loadable, string my_name, int my_score)
        auto self = loadable->cast<Scene>();

        auto result_popup = self->findByNamePath("./*/ui/popup.result");
        unlikely (result_popup == null)
          return null_var;


        App::project().pushTask<vector<RankItem>>(
            [my_name, my_score](auto result) {
              auto& rank_items = result->v;

              // load rank_items
              auto rank_sav_path = "saves/rank.sav";
              likely (File::exists(rank_sav_path) == true) {
                // load
                shared_ptr<paw_print::Cursor> root;
                {
                  string content;
                  File::readAll(rank_sav_path, content);

                  auto paw = paw_print::PawPrintLoader::loadText(rank_sav_path, content.c_str());
                  root = paw_print::PawPrint::root(paw);
                }

                // parse
                for (int ei=0; ei<root->size(); ++ei) {
                  auto e = root->getElem(ei);
                  auto name  = e->getElem("name" )->get("");
                  auto score = e->getElem("score")->get(0);

                  rank_items.push_back({name, score});
                }
              }


              // add my score and sort
              rank_items.push_back({my_name, my_score});
              std::sort(rank_items.begin(), rank_items.end(), [](RankItem const& a, RankItem const& b) { return a.score > b.score; });
              unlikely (rank_items.size() > 10)
                rank_items.resize(10);


              // save rank_items
              {
                auto paw = make_shared<PawPrint>("rank.sav");
                paw->beginSequence();
                  for (auto& itm : rank_items) {
                    paw->beginMap();
                      paw->pushKey("name" );  paw->pushString(itm.name );
                      paw->pushKey("score");  paw->pushSint4B(itm.score);
                    paw->endMap();
                  }
                paw->endSequence();

                auto serialized = PawPrint::root(paw)->serialize(rank_sav_path);
                auto content = PawPrint::root(serialized)->toString();
                fs::create_directory(DirInfo::root_dir() + "/saves");
                File::writeAll(rank_sav_path, content.data());
              }

            },
            [result_popup, my_score](auto result) {
              // update
              result_popup->callFunc("setRank", {Var(&result->v), Var(my_score)});
            }
        );
      '''

    'showBlingEffect':
      '''{(NodeLoadable* loadable, real x, real y)
        auto self = loadable->cast<Scene>();

        auto& gs = self->getDataRef("game_state").v<sp<GameState>>();
        auto& gd = self->getDataRef("game_data" ).v<sp<GameData >>();

        auto b = gd->blings[gd->next_bling_idx];
        b->setAction(null, "");
        b->x(x);
        b->y(y);
        b->setAction("show");

        gd->next_bling_idx = (gd->next_bling_idx + 1) % gd->blings.size();
      '''


  hip_part:
    '''{
      sp<fun_tree::Content> GameState::convertToMap () {

        auto paw = make_shared<PawPrint>("game_state");
        paw->beginMap();
        paw->endMap();


        return fun_tree::PawPrintParser::parse(PawPrint::root(paw));
      }


      void GameState::setByMap (sp<fun_tree::Content> const& map) {
        unlikely (map == null || map->type() != Content::Type::MAP) {
          LOG("[warn]  state of GameState must be a Map");
          return;
        }
        auto state = dpc<Map>(map);

      }


      bool GameState::isOnWall (BoardCoord const& pos) {
        for (auto& wp : wall_poses) {
          auto overlaped = wp.x == pos.x && wp.y == pos.y;
          unlikely (overlaped == true)
            return true;
        }

        return false;
      }


      void GameState::speedUp (GameData* gd) {
        auto elapsed_ratio = gd->elapsed_time / snake_speed_spt;
        snake_speed_spt = math::max(snake_min_speed_spt, snake_speed_spt / snake_acc_spt);
        gd->elapsed_time = elapsed_ratio * snake_speed_spt;
      }


      void GameState::levelUp () {

        // make wall
        likely (isOnBoard(banana_pos) == true)
          wall_poses.push_back(banana_pos);

        // move pos infos for expanding board
        auto old_w = board_w;
        auto old_h = board_h;
        board_w = math::min(11, board_w + 2);
        board_h = math::min(11, board_h + 2);

        auto delta_w = (board_w - old_w) / 2;
        auto delta_h = (board_h - old_h) / 2;
        snake_head_pos.x += delta_w;
        snake_head_pos.y += delta_h;
        for (auto& sa : snake_action_history) {
          sa.pos.x += delta_w;
          sa.pos.y += delta_h;
        }
        for (auto& wp : wall_poses) {
          wp.x += delta_w;
          wp.y += delta_h;
        }

        level += 1;
        apple_left = level;

        need_tile_show_action = delta_w != 0 || delta_h != 0;
      }


      void GameData::processInput (GameState* gs) {
        // process input
        likely (gs->snake_action_history.size() > 0) {
          auto& last_action = gs->snake_action_history.back();
          auto already_act =
                 last_action.pos.x == gs->snake_head_pos.x + gs->snake_velocity.x
              && last_action.pos.y == gs->snake_head_pos.y + gs->snake_velocity.y;
          unlikely (already_act == true)
            return;
        }

        static vector<KeyEventType> keys_for_turn =
            {KeyEventType::KEY_LEFT, KeyEventType::KEY_UP, KeyEventType::KEY_RIGHT, KeyEventType::KEY_DOWN};
        int dir_idx = gs->getSnakeDirIdx();  // up, right, down, left
        auto left_turn_key  = keys_for_turn[dir_idx];
        auto right_turn_key = keys_for_turn[(dir_idx + 2) % 4];

        if (last_key_type == left_turn_key) {
          gs->snake_action_history.push_back({
              SnakeActionType::TURN_LEFT,
              {gs->snake_head_pos.x + gs->snake_velocity.x, gs->snake_head_pos.y + gs->snake_velocity.y},
          });
          await_action_count = 1;
          last_key_type = KeyEventType::KEY_NONE;
        }else if (last_key_type == right_turn_key) {
          gs->snake_action_history.push_back({
              SnakeActionType::TURN_RIGHT,
              {gs->snake_head_pos.x + gs->snake_velocity.x, gs->snake_head_pos.y + gs->snake_velocity.y},
          });
          await_action_count = 1;
          last_key_type = KeyEventType::KEY_NONE;
        }
      }


      static void __updateVelByActionHistory (
          size_t& history_idx_from_top,
          BoardCoord const& cur_pos,
          BoardCoord& vel,
          vector<SnakeAction> const& snake_action_history
      ) {
        unlikely (history_idx_from_top >= snake_action_history.size())
          return;

        auto& snake_action = snake_action_history[snake_action_history.size() - history_idx_from_top - 1];
        auto has_action = cur_pos.x == snake_action.pos.x && cur_pos.y == snake_action.pos.y;
        likely (has_action == false)
          return;

        switch (snake_action.type) {
          case SnakeActionType::TURN_LEFT:
            vel = (vel.x == 0)? BoardCoord{vel.y, 0}: BoardCoord{0, -vel.x};
            break;

          case SnakeActionType::TURN_RIGHT:
            vel = (vel.x == 0)? BoardCoord{-vel.y, 0}: BoardCoord{0, vel.x};
            break;

          case SnakeActionType::EAT_APPLE:
            break;
        }

        history_idx_from_top += 1;

        return __updateVelByActionHistory(history_idx_from_top, cur_pos, vel, snake_action_history);
      }


      void GameData::updateSnake (GameState* gs) {
        const real kSnakeZPerBody = REAL( 0.1);
        const real kSnakeTailSclY = REAL( 0.5);
        const int kSnakeBodyCntPerTile = 4;

        real elapsed_ratio = (real)(elapsed_time / gs->snake_speed_spt);

        snake_body_poses.clear();


        { // snake face
          auto tile_idx = gs->snake_head_pos.y * gs->board_w + gs->snake_head_pos.x;
          auto t = tiles[tile_idx];
          snake_face_cmp->position({
              t->x() + tile_w * gs->snake_velocity.x * elapsed_ratio,
              t->y() + tile_w * gs->snake_velocity.y * elapsed_ratio,
              REAL(0.0),
          });
          snake_body_poses.push_back(gs->snake_head_pos);
          
          auto scl_x = snake_face_cmp->scale().x();
          if (gs->snake_velocity.x > 0)
            scl_x = REAL(-1.0);
          else if (gs->snake_velocity.x < 0)
            scl_x = REAL(1.0);
          snake_face_cmp->scale({scl_x, REAL(1.0), REAL(1.0)});

          snake_face_cmp->callFunc("select", {Var("happy")});
        }


        int total_body_cnt = gs->snake_length * kSnakeBodyCntPerTile - 1;
        { // snake bodies
          // hide all bodies
          for (auto& b : snake_bodies)
            b->is_drawable_self(false);

          // apply bodies
          size_t history_idx_from_top = await_action_count;
          BoardCoord vel = gs->snake_velocity;
          BoardCoord prev_vel = vel;
          __updateVelByActionHistory(history_idx_from_top, gs->snake_head_pos, vel, gs->snake_action_history);
          BoardCoord cur_pos = {gs->snake_head_pos.x - vel.x, gs->snake_head_pos.y - vel.y};
          BoardCoord prev_pos = gs->snake_head_pos;

          for (byte si=1; si<gs->snake_length; ++si) {

            unlikely (gs->isOnBoard(cur_pos) == false)
              break;

            snake_body_poses.push_back(cur_pos);

            // ready
            auto prev_tile_idx = prev_pos.y * gs->board_w + prev_pos.x;
            auto prev_tile = tiles[prev_tile_idx];

            auto tile_idx = cur_pos.y * gs->board_w + cur_pos.x;
            auto tile = tiles[tile_idx];
            
            // set bodies
            for (int bi=(si-1)*kSnakeBodyCntPerTile; bi<si*kSnakeBodyCntPerTile; ++bi) {
              auto& b = snake_bodies[bi];

              auto bi_ratio = REAL(1.0) - (((bi % kSnakeBodyCntPerTile)+1) / (real)kSnakeBodyCntPerTile) + elapsed_ratio;
              if (bi_ratio > REAL(1.0)) {
                // case: use prev
                bi_ratio -= REAL(1.0);
                b->position({
                  tile_w * prev_vel.x * bi_ratio + prev_tile->x(),
                  tile_w * prev_vel.y * bi_ratio + prev_tile->y(),
                  REAL(0.0),
                });
              }else {
                // case: use cur
                b->position({
                  tile_w * vel.x * bi_ratio + tile->x(),
                  tile_w * vel.y * bi_ratio + tile->y(),
                  REAL(0.0),
                });
              }
              //auto scl = (REAL(1.0) - kSnakeTailSclY) * (total_body_cnt-bi-1) / (real)(total_body_cnt-1) + kSnakeTailSclY;
              auto scl = REAL(1.0);
              b->getChild(0)->scale({
                  scl,
                  scl,
                  REAL(1.0),
              });
              b->is_drawable_self(true);
            }


            // check has action and rotate
            prev_vel = vel;
            __updateVelByActionHistory(history_idx_from_top, cur_pos, vel, gs->snake_action_history);

            prev_pos = cur_pos;
            cur_pos = {cur_pos.x - vel.x, cur_pos.y - vel.y};
          }
        }


        { // set z values
          // sort by tail-to-head
          vector<GameComponent*> tail_to_head_bodies;
          for (int bi=total_body_cnt-1; bi>=0; --bi)
            tail_to_head_bodies.push_back(snake_bodies[bi]);

          // sort by desc y
          vector<GameComponent*> sorted_bodies;
          while (sorted_bodies.size() < tail_to_head_bodies.size()) {
            real max_y = REAL(-100000.0);
            size_t idx_of_max = 0;
            for (size_t ti=0; ti<tail_to_head_bodies.size(); ++ti) {
              auto& bd = tail_to_head_bodies[ti];
              unlikely (bd == null)
                continue;

              unlikely (max_y < bd->y()) {
                max_y = bd->y();
                idx_of_max = ti;
              }
            }

            sorted_bodies.push_back(tail_to_head_bodies[idx_of_max]);
            tail_to_head_bodies[idx_of_max] = null;
          }

          // set bodies.z
          real z = REAL(0.0);
          for (auto& bd : sorted_bodies) {
            bd->z(z);
            z += kSnakeZPerBody;
          }

          // set face.z
          snake_face_cmp->z(z);
        }
      }


      bool GameData::isOnBody (BoardCoord const& pos, bool skip_tail/*=*/) {

        size_t body_size = snake_body_poses.size();
        unlikely (skip_tail == true)
          body_size -= 1;

        for (size_t si=0; si<body_size; ++si) {
          auto& bp = snake_body_poses[si];
          auto overlaped = bp.x == pos.x && bp.y == pos.y;
          unlikely (overlaped == true)
            return true;
        }

        return false;
      }


      static BoardCoord __findPlace (GameState* gs, GameData* gd) {
        unlikely (gs->snake_length >= gs->board_w*gs->board_h)
          return {-1, -1};

        // find pos to place
        while (true) {
          BoardCoord pos = {
              DefaultRandomPocket::draw(0, gs->board_w - 1),
              DefaultRandomPocket::draw(0, gs->board_h - 1),
          };

          auto is_on_wall = gs->isOnWall(pos);
          unlikely (is_on_wall == true)
            continue;

          auto is_on_body = gd->isOnBody(pos);
          unlikely (is_on_body == true)
            continue;

          return pos;
        }

        return {-1, -1};
      }


      void GameData::placeApple (Scene* scene, GameState* gs) {
        gs->apple_pos = __findPlace(gs, this);

        auto has_apple_on_board = gs->isOnBoard(gs->apple_pos);
        likely (has_apple_on_board == true) {
          byte idx = gs->apple_pos.y * gs->board_w + gs->apple_pos.x;
          auto t = tiles[idx];
          apple_cmp->position({t->x(), t->y(), REAL(0.0)});
          apple_cmp->findChild<GameObject>("txt")->setText(to_string(gs->apple_left));
          apple_cmp->setAction("show");

        }else {
          apple_cmp->is_drawable_self(false);
        }

      }


      void GameData::placeBanana (Scene* scene, GameState* gs) {
        gs->banana_pos = __findPlace(gs, this);

        auto has_banana_on_board = gs->isOnBoard(gs->banana_pos);
        likely (has_banana_on_board == true) {
          byte idx = gs->banana_pos.y * gs->board_w + gs->banana_pos.x;
          auto t = tiles[idx];
          banana_cmp->position({t->x(), t->y(), REAL(0.0)});
          banana_cmp->setAction("show");

        }else {
          banana_cmp->is_drawable_self(false);
        }
      }
    '''
