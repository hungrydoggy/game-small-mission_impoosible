%Envelope%:

  include_part:
    '''{
      #include <algorithm>
      #include <filesystem>

      #include <plugins/cooldown/cooldown.h>
      #include <plugins/cooldown/cooldown_manager.h>
    '''

  neck_part:
    '''{
      using namespace appetizer;

      using std::to_string;
      namespace fs = std::filesystem;


      static void __onBeforeInit (GameObject* self);
    '''

  val:
    '%onBeforeInit':
      '''{(GameObject* self)
        __onBeforeInit(self);
      '''

    '~onHpUpdated':
      '''{(GameObject* self, ,,, vector<Var> msg_params)
        unlikely (msg_params.size() < 1) {
          LOG_ERR("need params --- int cur_hp");
          return null_var;
        }

        self->sendMessage("/camera/hp", "setHp", {msg_params[0]});
      '''

    '~incScore':
      '''{(GameObject* self, ,,, vector<Var> msg_params)
        unlikely (msg_params.size() < 1) {
          LOG_ERR("need params --- int score_inc");
          return null_var;
        }

        auto score_inc = msg_params[0].as<int>();

        auto score = math::clamp(self->scene()->getData("score", 0) + score_inc, 0, 99999);
        self->scene()->setData("score", score);
        self->sendMessage("/camera/score", "setScore", {Var(score)});
      '''

  hip_part:
    '''{
      void __onBeforeInit (GameObject* self) {

        // cooldown_manager
        auto cooldown_manager = make_shared<CooldownManager>();
        self->addTrait(cooldown_manager);

        cooldown_manager->addCooldown(
            "poop_create_interval",
            make_shared<Cooldown>(
              0.5,
              1
            )
        );
      }
    '''
