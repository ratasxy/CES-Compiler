cmake_minimum_required(VERSION 3.5)
project(CES)

find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp File.cpp File.h LexicalAnalyzer.cpp LexicalAnalyzer.h SymTable.cpp colors.h)
add_executable(CES ${SOURCE_FILES})
target_link_libraries(CES ${Boost_LIBRARIES})
