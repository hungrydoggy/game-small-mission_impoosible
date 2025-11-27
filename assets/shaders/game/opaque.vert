#version 460

#include "./opaque.bind.glsl"



/// in
layout (location = 0) in vec3 i_position;
layout (location = 1) in vec2 i_st;
layout (location = 2) in uint i_obj_idx;



/// out
layout (location = 0) out vec2  o_st;
layout (location = 1) out uint  o_obj_idx;



vec3 _fetchVAT (uint vat_idx, vec2 uv, float u_add, vec4 offset_scl) {
  return texture(sampler2DArray(texture_array, sampler_0), vec3(uv + vec2(u_add, 0), vat_idx)).xyz * offset_scl.w + offset_scl.xyz;
}


void main () {
  uint obj_idx = i_obj_idx;
  ObjectData obj_data = obj_buff.data[obj_idx];

  float vat_progress = ((obj_data.bpk_3oldvat_3vat_8vatprg_3sam_3tex >>  6) & 0xff) / 255.f;
  uint  vat_idx      =  (obj_data.bpk_3oldvat_3vat_8vatprg_3sam_3tex >> 14) & 0x07;
  uint  old_vat_idx  =  (obj_data.bpk_3oldvat_3vat_8vatprg_3sam_3tex >> 17) & 0x07;

  uint vertex_idx = gl_VertexIndex - obj_data.dst_vertex_offset;

  vec3 vat     = _fetchVAT(    vat_idx,  obj_data.    vat_uv,  obj_data.    vat_u_unit * vertex_idx,  obj_data.    vat_offset_scl);
  vec3 old_vat = _fetchVAT(old_vat_idx,  obj_data.old_vat_uv,  obj_data.old_vat_u_unit * vertex_idx,  obj_data.old_vat_offset_scl);
  vec3 vat_result = (vat * vat_progress) + (old_vat * (1.f - vat_progress));

  vec4 prj_pos = obj_data.transform * vec4(i_position + vat_result, 1.0f);
	gl_Position = prj_pos;

  o_st = i_st;
  o_obj_idx = obj_idx;
}

