cmake_minimum_required(VERSION 3.10)

# Project name
project(app_one)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler warnings and conformance
if(MSVC)
  # Windows/Visual Studio settings (matching .vcxproj)
  add_compile_options(/W4)
  add_compile_options(/permissive-)  # ConformanceMode=true
else()
  # Linux/GCC/Clang settings
  add_compile_options(-Wall)
  add_compile_options(-pedantic)
endif()

# Create executable
add_executable(
  app_one
  main.cpp
  add.cpp
)
