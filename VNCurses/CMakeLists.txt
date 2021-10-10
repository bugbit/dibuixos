cmake_minimum_required(VERSION 3.0.0)
project(Dibuixos VERSION 0.1.0)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c")
 
add_executable(Dibuixos ${SOURCES})

target_precompile_headers(Dibuixos PRIVATE src/pch.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

target_link_libraries(Dibuixos ${CURSES_LIBRARIES})
