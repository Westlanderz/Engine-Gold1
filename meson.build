project('ECS', 'cpp', 'c', default_options : ['warning_level=3', 'werror=true'], version: '0.1.0')

cpp_compiler = meson.get_compiler('cpp')
c_compiler = meson.get_compiler('c')
add_project_arguments('--std=c++20', '-c', '-fcoroutines', '-ggdb', '-O0', language: 'cpp')
add_project_arguments('--std=c17', '-c', '-ggdb', '-O0', language: 'c')
add_project_arguments('-pedantic', '-Wshadow', '-Wpointer-arith', '-Wcast-align', '-Wwrite-strings', '-Wmissing-declarations', '-Wredundant-decls', '-Winline', '-Wno-long-long', '-Wconversion', language: 'cpp')
add_project_arguments('-I../lib/glad/include', language: 'cpp')
add_project_arguments('-I../lib/glad/include', language: 'c')
add_project_arguments('-Wno-pedantic', language: 'c')

add_project_link_arguments('-lglfw', '-lGL', '-lX11', '-lpthread', '-lXrandr', '-lXi', '-ldl', language: 'cpp')

subdir('src')
