cmake_minimum_required(VERSION 3.20)

project(TELite)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# if we forgot to set the build type default to release
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release"
      CACHE STRING "One of: Debug Release RelWithDebInfo MinSizeRel"
      FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY
        STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "Configuring a ${CMAKE_BUILD_TYPE} build")

if (NOT CMAKE_CXX_FLAGS)
    set(tmp "-Wall -Wextra")
    if ("${CMAKE_BUILD_TYPE}" MATCHES "Release")
        set(tmp "${tmp} -O3 -march=native -mtune=native")
    endif()
    set(CMAKE_CXX_FLAGS "${tmp}"
        CACHE STRING "TELite build defaults"
        FORCE)
endif()

# set build/install sub dirs for various components
if (NOT LIB_PREFIX)
  set(LIB_PREFIX lib)
endif()
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIB_PREFIX})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIB_PREFIX})
if (NOT INCLUDE_PREFIX)
  set(INCLUDE_PREFIX include)
endif()

add_subdirectory(src)

target_link_libraries(TELite)
