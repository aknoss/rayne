cmake_minimum_required(VERSION 4.0.3)
project(app)

add_subdirectory(vendored/SDL)

add_executable(
  rayne 
  src/main.cpp 
  src/game_manager.cpp 
  src/render_manager.cpp
)

target_link_libraries(rayne PRIVATE SDL3::SDL3)
