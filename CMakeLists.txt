cmake_minimum_required(VERSION 3.14)
project(CpuEmulator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Get Gtest and enable Testing
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# define source directory
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

#define .h files
include_directories(${SOURCE_DIR}/public)
#define .cpp files
file(GLOB SOURCES ${SOURCE_DIR}/private/*.cpp)

# define .cpp files as executable
add_executable(${PROJECT_NAME} ${SOURCES})

# include GTEST
target_link_libraries(
  ${PROJECT_NAME} GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})