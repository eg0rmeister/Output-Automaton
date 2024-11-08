cmake_minimum_required(VERSION 3.28)
project(output-automaton)

set(SOURCES Sources)

enable_testing()

include_directories(Include)
add_subdirectory(${SOURCES} ${SOURCES})
link_libraries(AutomatonAndInputs)

add_subdirectory(Tests Tests)

add_executable(main.out main.cpp)