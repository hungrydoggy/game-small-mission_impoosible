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
        self->sendMessage("/camera/score", "setScore", {Var(self->getData("score", 0))});
      '''

    '%onKeyInput':
      '''{(Scene* self, KeyEvent const* e)
        self->sendMessage("/scene_state", "onKeyInput", {Var(e)});
      '''

  hip_part:
    '''{
    '''
