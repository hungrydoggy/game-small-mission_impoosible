#ifndef MY_PROJECT_H_
#define MY_PROJECT_H_


#include <appetizer.h>
#include <util/collada_parser.h>


using namespace appetizer;


class GAMECONTENT_API MyProject: public Project {
  using super = Project;

public:
  bool preInitGpu (GLFWwindow*& window, string& project_name) override;


private:
  bool _onInit () override;
};

#endif  // ifndef MY_PROJECT_H_
