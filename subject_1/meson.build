#######################################
#                CONFIG               #
#######################################
project('recruitment', ['c', 'cpp'], version : '1.0.0', default_options : [
            'c_std=c18',
            'warning_level=2',
            'default_library=static',

            'b_sanitize=address',
            'buildtype=debug',
            'werror=true',
        ])

cflags = ['-D_XOPEN_SOURCE=500', '-D_POSIX_C_SOURCE=200809L']
add_project_arguments(cflags, language: 'c')

#######################################
#              DEPENDANCE             #
#######################################
cc = meson.get_compiler('c')
readline_dep = cc.find_library('readline', required: true)
if get_option('unit')
    gtest_dep = cc.find_library('gtest', required: false)
endif

#######################################
#                SOURCE               #
#######################################
include = 'src'
lib_src = []
bin_src = []
subdir('src')

if get_option('unit')
    unit_src = []
    subdir('tests')
endif

#######################################
#                BUILD                #
#######################################

# LIBRARY
lib = library('', lib_src, include_directories: include)

# BINNARY
bin = executable('myvswitch',
                 sources: bin_src,
                 install: true,
                 link_with: lib,
                 include_directories: [include],
                 dependencies: [readline_dep])

if get_option('unit')
    unit = executable('unit',
                    sources: unit_src,
                    link_with: lib,
                    include_directories: [include, 'tests'],
                    dependencies: [readline_dep, gtest_dep])
endif

#######################################
#                TESTS                #
#######################################

gtest_args = ['--gtest_color=yes']

if get_option('unit')
    test('unit', unit, args: gtest_args, priority: 1)
endif

# echo = find_program('echo')
#

#######################################
#            DOCUMENTATION            #
#######################################

if get_option('docs')
    subdir('docs')
endif
