cmake_minimum_required(VERSION 3.0)
project(temp)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

## Compile as C++11
add_compile_options(-std=c++11)
# you may need to use the later standard if compilation errors occur

set(EXAMPLE_SRC
  src/example/example.cc
)

include_directories(src)
add_library(${PROJECT_NAME}_example ${EXAMPLE_SRC})
add_executable(${PROJECT_NAME} src/main.cc)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_example)

# Support test
set(TEST_SOURCE test/test_example)
add_executable(${PROJECT_NAME}-test ${EXAMPLE_SRC} ${TEST_SOURCE})
target_link_libraries(${PROJECT_NAME}-test gtest_main)
