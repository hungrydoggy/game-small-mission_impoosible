
/// consts
const uint  kMaxWidthPixel     = 1920;
const uint  kMaxHieghtPixel    = 1080;
const uint  kMaxFragColorCount = 8;
const float kMaxDepth          = 10000.0f;


/// buffers
layout(set=0, binding=0)
#include "./common/global_data.glsl"


#include "./common/object_data.glsl"
layout(set=1, binding=0) readonly buffer ObjectBuffer{
  ObjectData data[];
} obj_buff;


layout (set=1, binding=1) uniform sampler        sampler_0;
layout (set=1, binding=2) uniform sampler        sampler_1;
layout (set=1, binding=3) uniform sampler        sampler_2;
layout (set=1, binding=4) uniform sampler        sampler_3;
layout (set=1, binding=5) uniform texture2DArray texture_array;


