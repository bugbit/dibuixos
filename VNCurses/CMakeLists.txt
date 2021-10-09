cmake_minimum_required(VERSION 3.7.2)
project(Dibuixos VERSION 0.1.0)

IF (WIN32)
    set(CMAKE_CXX_FLAGS "-DNOPCH")
    include_directories("${LIBS_PATH}/include")
    include_directories("${LIBS_PATH}/include/pdcurses")
    link_directories("${LIBS_PATH}/windows/pdcurses/")
ELSE ()
    find_package(Curses REQUIRED)
    include_directories(${CURSES_INCLUDE_DIR})
ENDIF (WIN32)

include_directories("./src")
file (GLOB app_SOURCES src/*.c)

add_executable(Dibuixos ${app_SOURCES})
IF (WIN32)
    target_link_libraries(Dibuixos pdcurses)
ELSE ()
    target_precompile_headers(Dibuixos PRIVATE src/pch.h)
    target_link_libraries(Dibuixos ${CURSES_LIBRARY})
ENDIF (WIN32)
install(TARGETS Dibuixos RUNTIME DESTINATION ${BIN_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

