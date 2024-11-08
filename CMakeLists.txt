cmake_minimum_required(VERSION 3.28)
project(output-automaton)

set(SOURCES Sources)

include_directories(Include)

add_executable(a.out main.cpp ${SOURCES}/Automaton.cpp ${SOURCES}/UserInput.cpp ${SOURCES}/GeneralInput.cpp)