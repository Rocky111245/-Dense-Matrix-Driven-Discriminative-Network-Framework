cmake_minimum_required(VERSION 3.26)
project(_Discriminative_Dense_Neural_Network_Framework)

set(CMAKE_CXX_STANDARD 23)

# Add an executable target called _Discriminative_Dense_Neural_Network_Framework to the project using the specified source file
add_executable(_Discriminative_Dense_Neural_Network_Framework main.cpp)

# Specify the directory where the header file can be found
target_include_directories(_Discriminative_Dense_Neural_Network_Framework PRIVATE "-----")

# Specify the directory where the .dll and .lib files can be found for linking
# Assuming the .lib file is located in the cmake-build-debug directory or its "lib" subdirectory
target_link_directories(_Discriminative_Dense_Neural_Network_Framework PRIVATE "-----")
target_link_libraries(_Discriminative_Dense_Neural_Network_Framework PRIVATE CMatrixLibrary)
