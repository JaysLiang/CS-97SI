cmake_minimum_required(VERSION 2.8)

project(CS-97SI)


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FILE(GLOB_RECURSE chapter ${CMAKE_CURRENT_SOURCE_DIR}/chapter*/*.cpp)

MESSAGE(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE(STATUS ${chapter})
FOREACH(solution ${chapter})
    MESSAGE(${solution})
    GET_FILENAME_COMPONENT(solution_name ${solution} NAME_WE)
    ADD_EXECUTABLE(${solution_name} ${solution})
ENDFOREACH()

