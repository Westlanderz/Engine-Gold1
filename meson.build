project('ECS', 'cpp', default_options : ['warning_level=3', 'werror=true'], version: '0.1.0')

cpp_compiler = meson.get_compiler('cpp')
add_project_arguments('--std=c++20', '-c', '-fcoroutines', '-ggdb', '-Og', language: 'cpp')
add_project_arguments('-pedantic', '-Wshadow', '-Wpointer-arith', '-Wcast-align', '-Wwrite-strings', '-Wmissing-declarations', '-Wredundant-decls', '-Winline', '-Wno-long-long', '-Wconversion', language: 'cpp')

subdir('src')
