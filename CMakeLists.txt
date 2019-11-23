cmake_minimum_required(VERSION 3.10)
# set the project name
project(NeuralNetwork2)
# add sub directory
add_subdirectory(NeuralNet)
# add the executable
add_executable(${PROJECT_NAME} main.cpp)
# add target library
target_link_libraries(${PROJECT_NAME} NeuralNet)
# add include dir
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/NeuralNetworkLib/include)
