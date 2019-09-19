cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(This FlexyList)

project(${This} VERSION 0.0.1
    DESCRIPTION "Just another linked list implementation"
    LANGUAGES CXX
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Enable testing
include(CTest)

# Setup the main library
add_library(${This} INTERFACE)

target_include_directories(${This} INTERFACE ${PROJECT_SOURCE_DIR}/include)

# Add the tests subdirectory
add_subdirectory(tests)