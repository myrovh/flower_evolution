cmake_minimum_required(VERSION 3.2)
project(fit3094_ai_assignment2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(fit3094_ai_assignment2 ${SOURCE_FILES} GL_routines.h GL_routines.cpp Flower.cpp Flower.h World.cpp World.h)
target_link_libraries(fit3094_ai_assignment2 ${OPENGL_LIBRARY} ${GLUT_LIBRARIES})