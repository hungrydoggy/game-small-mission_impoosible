%Envelope%:

  include_part:
    '''{
      #include <algorithm>
      #include <filesystem>
    '''

  neck_part:
    '''{
      using namespace appetizer;

      using std::to_string;
      namespace fs = std::filesystem;

    '''

  val:
    '%onInit':
      '''{(Scene* self)
        return null_var;
      '''

    '%onKeyInput':
      '''{(Scene* self, KeyEvent const* e)
        self->sendMessage("/scene_state", "onKeyInput", {Var(e)});
      '''

    '~onHpUpdated':
      '''{(Scene* self, ,,, vector<Var> msg_params)
        unlikely (msg_params.size() < 1) {
          LOG_ERR("need params --- int cur_hp");
          return null_var;
        }

        self->sendMessage("/camera/hp", "setHp", {msg_params[0]});
      '''

  hip_part:
    '''{
    '''
