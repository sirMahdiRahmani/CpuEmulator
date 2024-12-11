cmake_minimum_required(VERSION 3.27)
project(CpuEmulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# define source directory
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

#define .h files
include_directories(${SOURCE_DIR}/public)
#define .cpp files
file(GLOB SOURCES ${SOURCE_DIR}/private/*.cpp)

# define .cpp files as executable
add_executable(${PROJECT_NAME} ${SOURCES})
