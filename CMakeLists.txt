cmake_minimum_required(VERSION 3.10)

# Project name and version
project(StudyCards VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the subdirectory for nlohmann/json
add_subdirectory(json)

# Add executable for main.cpp
add_executable(StudyCards main.cpp)

# Link the nlohmann::json library to the StudyCards executable
target_link_libraries(StudyCards PRIVATE nlohmann_json)
