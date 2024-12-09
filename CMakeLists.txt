cmake_minimum_required(VERSION 3.27)
project(CppCmake)

#set(CMAKE_CXX_STANDARD 20)

# define source directory
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

#define .h files
include_directories(${SOURCE_DIR}/public)
#define .cpp files
file(GLOB SOURCES ${SOURCE_DIR}/private/*.cpp)

# define .cpp files as executable
add_executable(${PROJECT_NAME} ${SOURCES})
