cmake_minimum_required(VERSION 3.8)
project(lpa_prob2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp clean.cpp)
add_executable(lpa_prob2 ${SOURCE_FILES} )

execute_process(COMMAND ./lpa_prob2 INPUT_FILE test.txt)