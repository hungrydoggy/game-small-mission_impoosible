project('fun_game', 'c', 'cpp', default_options : ['cpp_std=c++20', 'buildtype=minsize'])


add_global_arguments('-D_STEAMDECK', language : 'cpp')
add_global_arguments('-D_LINUX', language : 'cpp')

add_global_arguments('-D_THREAD_SAFE', language : 'cpp')



## inc_dirs
inc_dirs = [
  include_directories('../../appetizer/src'),
  include_directories('../../appetizer/src/external'),
  include_directories('../../appetizer/external_libs/include'),
  include_directories('../../src'),
]


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
  dependency('gl'),
  dependency('glfw3'),
  dependency('bullet'),
  dependency('libpng'),
  dependency('freetype2'),
  #dependency('boost'),
  dependency('vulkan'),
]


# server_deps
server_deps = [
  dependency('bullet'),
]



## cpp_args
cpp_args = []
editor_cpp_args = ['-D_EDITOR', '-DDEBUG', '-DUSE_OBJID_SURF']
server_cpp_args = ['-DSERVER_ONLY']

link_args = [
  '-lpthread',
  '-ldl',
  '-L../../appetizer/external_libs/lib',
  '-L../../appetizer/out/steam_deck',
]

editor_link_args = [
  '-lpthread',
  '-ldl',
  '-L../../appetizer/external_libs/lib',
  '-L../../appetizer/out/steam_deck',
]


editor_cpp_args += [
]
link_args += [
]
editor_link_args += [
  '-lboost_system',
  '-lboost_regex',
]



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

game_content_lib = shared_library('game_content', srcs, dependencies : deps, include_directories : inc_dirs, link_args : link_args + ['-lappetizer'], cpp_args: cpp_args + ['-DGAMECONTENT_EXPORTS'])

#game_content_lib_editor = shared_library('game_content_editor', srcs, dependencies : editor_deps, include_directories : inc_dirs, link_args : editor_link_args + ['-lappetizer_editor'], cpp_args: editor_cpp_args + ['-DGAMECONTENT_EXPORTS'])

#game_content_lib_server = shared_library('game_content_server', srcs, dependencies : server_deps, include_directories : inc_dirs, link_args : link_args + ['-lappetizer_server'], cpp_args: server_cpp_args + ['-DGAMECONTENT_EXPORTS'])



#########################################################################
# runnable
libs = [
  game_content_lib,
]
srcs = run_command('python3', '../../find_src.py', '../../auto_generated_main').stdout().strip().split('\n')
if srcs[0] == ''
  srcs = []
endif
main_ext_srcs = run_command('python3', '../../find_src.py', '../../main_ext').stdout().strip().split('\n')
if main_ext_srcs[0] != ''
  srcs += main_ext_srcs
endif
executable('runnable', srcs, link_with : libs, dependencies : deps, include_directories : inc_dirs, link_args : link_args + ['-lappetizer'], cpp_args: cpp_args)



#########################################################################
# server
#libs = [
#  game_content_lib_server,
#]
#srcs = run_command('python3', '../../find_src.py', '../../auto_generated_main').stdout().strip().split('\n')
#if srcs[0] == ''
#  srcs = []
#endif
#executable('server', srcs, link_with : libs, dependencies : server_deps, include_directories : inc_dirs, link_args : link_args + ['-lappetizer_server'], cpp_args: server_cpp_args)



#########################################################################
# editor_viewer
#libs = [
#  game_content_lib_editor,
#]
#srcs = run_command('python3', '../../find_src.py', '../../auto_generated_main').stdout().strip().split('\n')
#if srcs[0] == ''
#  srcs = []
#endif
#executable('editor_viewer', srcs, link_with : libs, dependencies : editor_deps, include_directories : inc_dirs, link_args : editor_link_args + ['-lappetizer_editor'], cpp_args: editor_cpp_args)
