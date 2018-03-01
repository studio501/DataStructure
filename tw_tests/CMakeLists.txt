cmake_minimum_required(VERSION 3.4)

project(tw_tests)

set(header_dir ../headers)

add_executable(seqlist_test SeqListTest.cpp)
include_directories(seqlist_test ${header_dir})

