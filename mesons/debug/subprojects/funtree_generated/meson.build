project('funtree_generated_lib', 'c', 'cpp', default_options : ['cpp_std=c++20', 'buildtype=debug'])


build_sys = build_machine.system()



## inc_dirs
inc_dirs = [
  include_directories('../../../../appetizer/src'),
  include_directories('../../../../appetizer/src/external'),
  include_directories('../../../../appetizer/external_libs/include'),
  include_directories('../../../../src'),
]
if build_sys == 'windows'
  inc_dirs += [
    include_directories('C:/vcpkg/installed/x64-windows/include'),
  ]
endif


## dependencies
# deps
deps = [
  dependency('glfw3'),
  dependency('bullet'),
  dependency('libpng'),
  dependency('freetype2'),
  dependency('vulkan'),
]


# editor_deps
editor_deps = [
  dependency('glfw3'),
  dependency('bullet'),
  dependency('libpng'),
  dependency('freetype2'),
  dependency('vulkan'),
]
if build_sys == 'windows'
  deps += [
    dependency('bzip2'),
  ]
  editor_deps += [
    dependency('bzip2'),
  ]
endif


# server_deps
server_deps = [
  dependency('bullet'),
]



## cpp_args
cpp_args = ['-D_THREAD_SAFE']
editor_cpp_args = ['-D_THREAD_SAFE', '-D_EDITOR', '-DDEBUG', '-DUSE_OBJID_SURF', '-D_FUNTREE_GENERATED']
server_cpp_args = ['-D_THREAD_SAFE', '-DSERVER_ONLY']

if build_sys == 'linux'
  cpp_args        += ['-D_LINUX']
  editor_cpp_args += ['-D_LINUX']
  server_cpp_args += ['-D_LINUX']
elif build_sys == 'windows'
  cpp_args        += ['-D_WINDOWS', '-DBOOST_SYSTEM_NO_DEPRECATED', '-w']
  editor_cpp_args += ['-D_WINDOWS', '-DBOOST_SYSTEM_NO_DEPRECATED', '-w']
  server_cpp_args += ['-D_WINDOWS', '-DBOOST_SYSTEM_NO_DEPRECATED', '-w']
endif


prj_path_cmd = 'import os; print(os.path.abspath(r"@0@"), end="")'.format(join_paths(meson.current_source_dir(), '../../../../'))
prj_path = run_command('python3', '-c', prj_path_cmd, check: true).stdout()


link_args = [
  '-lpthread',
  '-ldl',
  '-L' + join_paths(prj_path, 'appetizer/external_libs/lib'),
  '-L' + join_paths(prj_path, 'appetizer/out/debug'),
  '-L' + join_paths(prj_path, 'build/debug'),
]

editor_link_args = [
  '-lpthread',
  '-ldl',
  '-L' + join_paths(prj_path, 'appetizer/external_libs/lib'),
  '-L' + join_paths(prj_path, 'appetizer/out/debug'),
  '-L' + join_paths(prj_path, 'build/debug'),
  '-L.',
]



# case of build_sys
if build_sys == 'windows'
  cpp_args += [
    '/Z7',
  ]
  editor_cpp_args += [
    '/Z7',
    '/EHa',
  ]
  server_cpp_args += [
    '/Z7',
  ]
  link_args += [
    '-LC:/vcpkg/installed/x64-windows/debug/lib',
    '-lwinmm',
    '-lws2_32',
  ]
  editor_link_args += [
    '-LC:/vcpkg/installed/x64-windows/debug/lib',
    '-lwinmm',
    '-lws2_32',
    '-lboost_system-vc143-mt-gd-x64-1_85',
  ]
elif build_sys == 'linux'
  cpp_args += [
    '-O0',
    '-g3',
  ]
  editor_cpp_args += [
    '-O0',
    '-g3',
  ]
  server_cpp_args += [
    '-O0',
    '-g3',
  ]
  link_args += [
  ]
  editor_link_args += [
    '-lboost_system',
    '-lboost_regex',
  ]
endif



##### build ####

#########################################################################
# funtree_generated lib
inc_dirs += [
  include_directories('../../../../assets'),
  include_directories('../../../../optional/funtree_generated_plugin'),
]

common_optional_srcs = ['../../../../optional/funtree_generated_plugin/plugin.cpp']



# funtree_generated_code lib
srcs = [] + common_optional_srcs
src_out = run_command('python3', '../../../../find_src.py', '../../../../funtree_generated/code_gen').stdout().strip()
if src_out != ''
  srcs += src_out.split('\n')
endif

funtree_generated_code = shared_library('funtree_generated_code', srcs, dependencies : editor_deps, include_directories : inc_dirs, link_args : editor_link_args + ['-lappetizer_editor', '-lgame_content_editor'], cpp_args: editor_cpp_args)



# funtree_generated_lambda lib
srcs = [] + common_optional_srcs
src_out = run_command('python3', '../../../../find_src.py', '../../../../funtree_generated/lambda_gen').stdout().strip()
if src_out != ''
  srcs += src_out.split('\n')
endif

funtree_generated_lambda = shared_library('funtree_generated_lambda', srcs, dependencies : editor_deps, include_directories : inc_dirs, link_args : editor_link_args + ['-lappetizer_editor', '-lgame_content_editor'], cpp_args: editor_cpp_args)



# funtree_generated_macro lib
srcs = [] + common_optional_srcs
src_out = run_command('python3', '../../../../find_src.py', '../../../../funtree_generated/macro_gen').stdout().strip()
if src_out != ''
  srcs += src_out.split('\n')
endif

funtree_generated_macro = shared_library('funtree_generated_macro', srcs, dependencies : editor_deps, include_directories : inc_dirs, link_args : editor_link_args + ['-lappetizer_editor', '-lgame_content_editor'], cpp_args: editor_cpp_args)



# funtree_generated_ftnlo lib
srcs = [] + common_optional_srcs
src_out = run_command('python3', '../../../../find_src.py', '../../../../funtree_generated/ftnlo_gen').stdout().strip()
if src_out != ''
  srcs += src_out.split('\n')
endif

funtree_generated_ftnlo = shared_library('funtree_generated_ftnlo', srcs, dependencies : editor_deps, include_directories : inc_dirs, link_args : editor_link_args + ['-lappetizer_editor', '-lgame_content_editor'], cpp_args: editor_cpp_args)



## funtree_generated & server
#srcs = ['../../../../optional/funtree_generated_link/linker.cpp']
#
#src_out = run_command('python3', '../../../../find_src.py', '../../../../funtree_generated').stdout().strip()
#if src_out != ''
#  srcs += src_out.split('\n')
#endif
#
#funtree_generated_lib = shared_library('funtree_generated', srcs, dependencies : deps, include_directories : inc_dirs, link_args : link_args + ['-lappetizer', '-lgame_content'], cpp_args: cpp_args)
#
#funtree_generated_lib_server = shared_library('funtree_generated_server', srcs, dependencies : server_deps, include_directories : inc_dirs, link_args : link_args + ['-lappetizer_server', '-lgame_content_server'], cpp_args: server_cpp_args)
