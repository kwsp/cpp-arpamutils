cmake_minimum_required(VERSION 3.12)
project(USPAMproc CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

find_package(OpenCV REQUIRED)

add_executable(demo 
  main.cpp 
  binfile.cpp
)
target_link_libraries(demo ${OpenCV_LIBS} fftw3)
