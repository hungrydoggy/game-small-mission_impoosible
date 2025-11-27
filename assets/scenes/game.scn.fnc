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
      '''{(Scene* scene)
        return null_var;
      '''

    '%onKeyInput':
      '''{(Scene* self, KeyEvent const* e)
        self->sendMessage("/scene_state", "onKeyInput", {Var(e)});
      '''

  hip_part:
    '''{
    '''
