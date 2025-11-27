#version 460

/// consts
const uint kMaxWidthPixel  = 1920;
const uint kMaxHieghtPixel = 1080;


/// buffers
layout(set=0, binding=0) uniform GlobalData {
  uint window_width;
  uint window_height;
  uint screen_width;
  uint screen_height;
} global_data;

layout(set=0, binding=1) readonly buffer SceneData {
  mat4 projview_mat;
  uint line_count;
  float line_alpha;
} scene_data;



/// in
layout(location = 0) in vec3 i_color;



/// out
layout (location = 0) out vec4 o_color;



/// others



void main() {
  o_color = vec4(i_color, scene_data.line_alpha);
}
