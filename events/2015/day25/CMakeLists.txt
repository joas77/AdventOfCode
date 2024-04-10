cmake_minimum_required(VERSION  3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(AOC_LIB         "aocLib")
set(SOLUTION_TARGET "solution")
set(AOC_LIB_PATH    ../../../aocLib/cpp)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -O2")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall")

# use this command to compile in debug mode
# inside of build folder
# cmake -DCMAKE_BUILD_TYPE=Debug ..
#set(DCMAKE_BUILD_TYPE   Debug)

project(@aoc20XXDayXX@ LANGUAGES CXX)

add_subdirectory(${AOC_LIB_PATH}    ${AOC_LIB_PATH}/build)


add_executable(${SOLUTION_TARGET}    solutions.cpp)

set(SOLUTION_LIB "solutionLib")

add_library(${SOLUTION_LIB} impl.cpp)
target_include_directories(${SOLUTION_LIB}  PUBLIC ${AOC_LIB_PATH}/include)
target_link_libraries(${SOLUTION_TARGET}    PUBLIC
    ${SOLUTION_LIB}
    ${AOC_LIB}
)