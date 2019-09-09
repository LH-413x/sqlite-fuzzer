cmake_minimum_required(VERSION 3.14)
project(sqlite_mutator)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")



#add_executable(sqlite_mutator main.cpp utils.h generator.h table.h random.h)
#add_executable(window_fuzzer window_fuzzer.cpp)
add_subdirectory(expr)