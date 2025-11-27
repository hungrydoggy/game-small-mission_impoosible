struct ObjectData {
  uint index_count;
  uint first_index;
  uint vertex_count;
  uint first_vertex;
  uint dst_index_offset;
  uint dst_vertex_offset;

  uint bpk_3oldvat_3vat_8vatprg_3sam_3tex;

  float vat_u_unit;
  float old_vat_u_unit;

  vec4 vat_offset_scl;
  vec4 old_vat_offset_scl;

  vec4 tex_rect;

  vec2 vat_uv;
  vec2 old_vat_uv;

  vec4 color_scale;

  mat4 transform;
};
