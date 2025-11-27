#version 460

#include "./opaque.bind.glsl"



/// in
layout (location = 0)      in vec2  i_st;
layout (location = 1) flat in uint  i_obj_idx;



/// out
layout (location = 0) out vec4  o_color;




vec4 _sampleTexture (uint tex_idx, uint sam_idx, vec2 uv) {

  vec3 sample_coord = vec3(uv, float(tex_idx));
  vec4 col0 = texture(sampler2DArray(texture_array, sampler_0), sample_coord);
  vec4 col1 = texture(sampler2DArray(texture_array, sampler_1), sample_coord);
  vec4 col2 = texture(sampler2DArray(texture_array, sampler_2), sample_coord);
  vec4 col3 = texture(sampler2DArray(texture_array, sampler_3), sample_coord);

  switch (sam_idx) {
    case 0: return col0;
    case 1: return col1;
    case 2: return col2;
    case 3: return col3;
    default:
      return col0;
  }
}


void main () {
  ObjectData obj_data = obj_buff.data[i_obj_idx];

  uint tex_idx = (obj_data.bpk_3oldvat_3vat_8vatprg_3sam_3tex     ) & 0x7;
  uint sam_idx = (obj_data.bpk_3oldvat_3vat_8vatprg_3sam_3tex >> 3) & 0x7;

  vec4 color =
      _sampleTexture(tex_idx, sam_idx, i_st * obj_data.tex_rect.zw + obj_data.tex_rect.xy) * obj_data.color_scale;
  if (color.a < 0.9)
    discard;


  //const float gamma = 2.2;
  //o_color.rgb = pow(color.rgb, vec3(gamma));
  //o_color.a = 1.0;

  o_color = color;
}
