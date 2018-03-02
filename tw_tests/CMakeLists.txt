cmake_minimum_required(VERSION 3.4)

project(tw_tests)

set(header_dir ../headers)

add_executable(seqlist_test SeqListTest.cpp)
include_directories(seqlist_test ${header_dir})

add_executable(bitree_test BiTreeTest.cpp)
include_directories(seqlist_test ${header_dir})

add_executable(stack_test Stack_test.cpp)
include_directories(stack_test ${header_dir})

add_executable(type_traits_test type_traits_test.cpp)
include_directories(type_traits_test ${header_dir})

