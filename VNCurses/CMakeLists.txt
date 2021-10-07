cmake_minimum_required(VERSION 3.7.2)
project(Dibuixos VERSION 0.1.0)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories("./src")
file (GLOB app_SOURCES src/*.c)

add_executable(Dibuixos ${app_SOURCES})
target_precompile_headers(Dibuixos PRIVATE src/pch.h)
target_link_libraries(Dibuixos ${CURSES_LIBRARY})
install(TARGETS Dibuixos RUNTIME DESTINATION ${BIN_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

