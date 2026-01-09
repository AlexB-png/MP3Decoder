cmake_minimum_required(VERSION 3.16)
project(MP3Decoder)

set(CMAKE_CXX_STANDARD 40)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)

add_executable(MP3Decoder main.cpp)

target_include_directories(MP3Decoder PRIVATE ${GTKMM_INCLUDE_DIRS})
target_compile_options(MP3Decoder PRIVATE ${GTKMM_CFLAGS_OTHER})
target_link_libraries(MP3Decoder PRIVATE ${GTKMM_LIBRARIES})
