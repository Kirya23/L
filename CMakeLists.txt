cmake_minimum_required(VERSION 3.5)
project(multifile)
set(SOURCE_FILES main.cpp Matrix.cpp Convolution.cpp Subsample.cpp )
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
