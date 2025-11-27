#version 460

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
layout (location = 0) in vec3 i_position;
layout (location = 1) in vec3 i_color;



/// out
layout(location = 0) out vec3 o_color;


mat4 _makeScaleMat (vec3 scale) {
  return mat4(
    scale.x, 0.0    , 0.0    , 0.0,
    0.0    , scale.y, 0.0    , 0.0,
    0.0    , 0.0    , scale.z, 0.0,
    0.0    , 0.0    , 0.0    , 1.0
  );
}

mat4 _makeTranslationMat (vec3 translation) {
  return mat4(
    1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    translation.x, translation.y, translation.z, 1.0
  );
}

void main () {
  gl_Position = scene_data.projview_mat * vec4(i_position, 1.0f);

  o_color = i_color;

	//o_texcoord =
	//		(
	//			_makeScaleMat(
	//				vec3(
	//					float(global_data.screen_width ) / float(global_data.window_width ),
	//					float(global_data.screen_height) / float(global_data.window_height),
	//					1
	//				)
	//			)
	//			* _makeTranslationMat(vec3(0.5, 0.5, 0.0))
	//			* _makeScaleMat(vec3(0.5, -0.5, 1))
	//			* vec4(i_position, 0.0f, 1.0f)
	//		).xy;
}

