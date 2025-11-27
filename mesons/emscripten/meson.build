project('fun_game', 'c', 'cpp', default_options : ['cpp_std=c++20', 'buildtype=minsize'])


build_sys = build_machine.system()
if build_sys == 'darwin'
  add_global_arguments('-D_OSX', language : 'cpp')
elif build_sys == 'cygwin'
  add_global_arguments('-D_LINUX', language : 'cpp')
  add_global_arguments('-D_XOPEN_SOURCE=500', language : 'cpp')
elif build_sys == 'linux'
  add_global_arguments('-D_LINUX', language : 'cpp')
elif build_sys == 'windows'
  add_global_arguments('-D_WINDOWS', language : 'cpp')
  add_global_arguments('-DBOOST_SYSTEM_NO_DEPRECATED', language : 'cpp')
  add_global_arguments('-w', language : 'cpp')
endif

add_global_arguments('-D_THREAD_SAFE', language : 'cpp')
add_global_arguments('-D_EMSCRIPTEN', language : 'cpp')
add_global_arguments('-DUSE_WEB_GPU', language : 'cpp')



## inc_dirs
inc_dirs = [
  include_directories('../../src'),
  include_directories('../../appetizer/external_libs/include'),
  include_directories('../../appetizer/src/external'),
  include_directories('../../appetizer/src'),
]
if build_sys == 'windows'
  inc_dirs += [
    include_directories('C:/vcpkg/installed/x64-windows/include'),
  ]
endif



## dependencies
deps = [
]



## cpp_args
common_args = [
  '--use-port=emdawnwebgpu',
  '-sUSE_GLFW=3',
  '-sUSE_BULLET=1',
  '-sUSE_PTHREADS=1',
  '-sPTHREAD_POOL_SIZE=1',
  '-sALLOW_MEMORY_GROWTH=1',
  '-sSTACK_SIZE=5242880',
  #'-sASYNCIFY',

  '-O3', '-DNDEBUG',
  #'-Oz',

  # for debug
  #'-O0',
  #'-gseparate-dwarf=index.dbg.wasm',
  #'-fdebug-compilation-dir=.',
]

cpp_args = [
]
cpp_args += common_args

link_args = [
  '-L../../appetizer/external_libs/lib',
  '-L../../appetizer/out/emscripten',
  '-oindex.html',
  '--bind',
  '--preload-file', '../../assets/actions/@/assets/actions', # for test
  '--preload-file', '../../assets/audio_clips/@/assets/audio_clips', # for test
  '--preload-file', '../../assets/baked/@/assets/baked', # for test
  '--preload-file', '../../assets/datas/@/assets/datas', # for test
  '--preload-file', '../../assets/gpu_tasks/@/assets/gpu_tasks', # for test
  '--preload-file', '../../assets/meshes/@/assets/meshes', # for test
  '--preload-file', '../../assets/objects/@/assets/objects', # for test
  '--preload-file', '../../assets/plugins/@/assets/plugins', # for test
  '--preload-file', '../../assets/scenes/@/assets/scenes', # for test
  '--preload-file', '../../assets/system/@/assets/system', # for test
  '--preload-file', '../../assets/textures/@/assets/textures', # for test
  '--preload-file', '../../appetizer/paw_print.tab@/paw_print.tab', # for test

  '-Wl,--whole-archive',
  '-lappetizer',
  '-Wl,--no-whole-archive'
]
link_args += common_args



##### build ####

#########################################################################
# game content lib
inc_dirs += [
  include_directories('../../assets'        ),
  include_directories('../../auto_generated'),
]
srcs = run_command('python3', '../../find_src.py', '../../assets').stdout().strip().split('\n')
if srcs[0] == ''
  srcs = []
endif
auto_generated_srcs = run_command('python3', '../../find_src.py', '../../auto_generated').stdout().strip().split('\n')
if auto_generated_srcs[0] != ''
  srcs += auto_generated_srcs
endif
src_srcs = run_command('python3', '../../find_src.py', '../../src').stdout().strip().split('\n')
if src_srcs[0] != ''
  srcs += src_srcs
endif

game_content_lib = static_library('game_content', srcs, dependencies : deps, include_directories : inc_dirs, link_args : link_args, cpp_args: cpp_args + ['-DGAMECONTENT_EXPORTS'])



#########################################################################
# funtree_generated lib
inc_dirs += [
  include_directories('../../assets'),
]
libs = [
  game_content_lib,
]
srcs = []

src_out = run_command('python3', '../../find_src.py', '../../funtree_generated').stdout().strip()
if src_out != ''
  srcs += src_out.split('\n')
endif


funtree_generated_lib = static_library('funtree_generated', srcs, link_whole : libs, dependencies : deps, include_directories : inc_dirs, link_args : link_args, cpp_args: cpp_args + ['-DGAMECONTENT_EXPORTS'])



#########################################################################
# runnable
libs = [
  #game_content_lib,
  funtree_generated_lib,
]
srcs = run_command('python3', '../../find_src.py', '../../auto_generated_main').stdout().strip().split('\n')
if srcs[0] == ''
  srcs = []
endif
main_ext_srcs = run_command('python3', '../../find_src.py', '../../main_ext').stdout().strip().split('\n')
if main_ext_srcs[0] != ''
  srcs += main_ext_srcs
endif
#funtree_generated_srcs = run_command('python3', '../../find_src.py', '../../funtree_generated').stdout().strip()
#if funtree_generated_srcs != ''
#  srcs += funtree_generated_srcs.split('\n')
#endif
link_args += [
  '-oindex.html',
]
executable('runnable', srcs, link_whole : libs, dependencies : deps, include_directories : inc_dirs, link_args : link_args, cpp_args: cpp_args, gui_app:true)


