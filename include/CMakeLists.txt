# add_library(stb_image stb_image.cpp)

add_library(includes
  STATIC
  VAO.cpp
  VBO.cpp
  EBO.cpp
  shaderClass.cpp
  texture.cpp
  renderer.cpp
)
include_directories(resources)
target_include_directories(includes PUBLIC ${PROJECT_SOURCE_DIR}/external/glfw/include ${PROJECT_SOURCE_DIR}/external/glad/include )
target_link_libraries(includes PRIVATE glfw glad glm)


