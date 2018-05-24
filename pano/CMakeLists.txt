cmake_minimum_required(VERSION 2.8)
project( stitching )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( stitching source.cpp )
add_definitions("-std=c++0x")
set_property(TARGET stitching PROPERTY CXX_STANDARD 11)
target_link_libraries( stitching ${OpenCV_LIBS} )

