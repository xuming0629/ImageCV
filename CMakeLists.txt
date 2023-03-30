cmake_minimum_required(VERSION 3.0.0)
project(ImageCV VERSION 0.1.0)

set(OpenCV_DIR "~/.local")
message(STATUS ${OpenCV_DIR})
find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    include_directories(${OpenCV_DIR}/include/opencv4/)
    include_directories( ${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_DIR}/lib)
    message(STATUS "Configure package with OpenCV!")
    set(HAVE_OpenCV True)
else()
    set(HAVE_OpenCV False)
    message(STATUS "Configure package without OpenCV!")
endif()

#add_executable(ImageCV main.cpp)
#add_executable(ImageCV 02_main.cpp)
add_executable(ImageCV 03_main.cpp)

target_link_libraries(ImageCV ${OpenCV_LIBS})

