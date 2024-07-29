cmake_minimum_required(VERSION 3.0)
project(OpenGL_libs)

add_subdirectory(external/glad)

add_subdirectory(external/glfw)

add_subdirectory(external/glm)

add_subdirectory(include)

add_subdirectory(src/options)

add_executable(${PROJECT_NAME} src/main.cpp )

target_include_directories(
    ${PROJECT_NAME} PRIVATE include/
)
  target_link_libraries(${PROJECT_NAME} PRIVATE includes glad Options 
    # Interface
)
