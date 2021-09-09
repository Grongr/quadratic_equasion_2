cmake_minimum_required(VERSION 3.16)
project(quadratic_equation)

set(LANGUAGE CXX)

add_executable(main main.c
                    qesolver.h qesolver.c
                    unitests.h unitests.c)

target_link_libraries(main m)
