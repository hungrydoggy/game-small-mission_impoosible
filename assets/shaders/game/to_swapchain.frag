#version 460

/// buffers
layout (set=0, binding=1) uniform sampler   color_sampler;
layout (set=0, binding=2) uniform texture2D opaque_color_texture;
layout (set=0, binding=3) uniform texture2D transparent_color_texture;



/// in
layout(location = 0) in vec2 i_texcoord;



/// out
layout (location = 0) out vec4 o_color;



/// others



void main() {
  vec4 opaq_col = texture(sampler2D(opaque_color_texture     , color_sampler), i_texcoord);
  vec4 trns_col = texture(sampler2D(transparent_color_texture, color_sampler), i_texcoord);

  //o_color.rgb = opaq_col.rgb * (1.0 - trns_col.a) + trns_col.rgb * trns_col.a;
  //o_color.a = 1.0;

  const float gamma = 1.0 / 2.2;
  o_color.rgb = pow(opaq_col.rgb * (1.0 - trns_col.a) + trns_col.rgb * trns_col.a, vec3(gamma));
  o_color.a = 1;
}
