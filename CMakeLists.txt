# CMakeList.txt : CMake project for lameenc, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("lameenc")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
find_package(Threads)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lame/)
link_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/lame/)

# Add source to this project's executable.
add_executable (${PROJECT_NAME} src/main.cpp "src/lameWrapper.cpp" "src/lameWrapper.h" "src/threadpool.cpp" "src/threadpool.h")

# TODO: Add tests and install targets if needed.
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
if(UNIX)
	target_link_libraries(${PROJECT_NAME} PRIVATE mp3lame m)
elseif(WIN32)
	target_link_options(${PROJECT_NAME} PRIVATE /machine:x86)
	target_link_libraries(${PROJECT_NAME} mp3lame)
endif()