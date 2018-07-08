cmake_minimum_required(VERSION 2.8.11)

# Project name
project(ikCore)

# Options
option(ikCORE_DEBUG "Compile ikCore in debug mode" OFF)
option(ikCORE_STATIC "Export ikCore to static library, if OFF, export to shared library" OFF)

if(ikCORE_DEBUG)
    set(CL_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build/Debug/output)
    set(CONFIGURATION_NAME "Debug")
else()
    set(CL_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build/Release/output)
    set(CONFIGURATION_NAME "Release")
endif()

# Locations
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CL_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CL_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CL_OUTPUT_DIRECTORY})


# Top project
# Define some variables
set(PROJECT_IKCORE_PATH "${CMAKE_CURRENT_LIST_DIR}")
set(WORKSPACE_PATH "${CMAKE_CURRENT_LIST_DIR}/..")

include_directories(
    .
    ./include

)

# Compiler options
add_definitions(-g)
add_definitions(-O0)
add_definitions(-Wall)
if(ikCORE_DEBUG)
    add_definitions(-DikDEBUG)
else()
    add_definitions(-DikNDEBUG)
endif()

# Library path
set(CMAKE_LDFLAGS "${CMAKE_LDFLAGS} -L. ")

# Define the CXX sources
set ( CXX_SRCS
# ${CMAKE_CURRENT_LIST_DIR}/source/ikCore/main.cxx
)


# set_source_files_properties(
#     ${CXX_SRCS} PROPERTIES COMPILE_FLAGS 
#     " -g -O0 -Wall")

if(WIN32)
    enable_language(RC)
    set(CMAKE_RC_COMPILE_OBJECT
        "<CMAKE_RC_COMPILER> ${RC_OPTIONS} -O coff -i <SOURCE> -o <OBJECT>")
endif(WIN32)

if(ikCORE_STATIC)
    add_library(ikCore ${RC_SRCS} ${CXX_SRCS} ${C_SRCS})
else()
    add_library(ikCore SHARED ${RC_SRCS} ${CXX_SRCS} ${C_SRCS})
    target_link_libraries(ikCore ${LINK_OPTIONS})
endif()
