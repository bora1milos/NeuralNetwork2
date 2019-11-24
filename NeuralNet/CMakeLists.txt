cmake_minimum_required(VERSION 3.10)
# set the project name
project(NeuralNet)
# add the executable

set (SOURCE source/NeuralNet.cpp 
            source/Layer.cpp 
            source/Matrix.cpp
            )

add_library(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
