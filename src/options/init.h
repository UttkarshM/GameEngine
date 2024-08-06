#pragma once
#include "../../include/shaderClass.h"
#include <iostream>
#include <memory>

#include "../../external/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <string>
namespace Engine {
struct Uniforms {
  std::string name;
  float c0;
  float c1;
  float c2;
  float c3;
};
class Init {
public:
  Init() = default;
  void InitOpenGL() const;
  void InitGlad() const;
  void GLframebuffer_size_callback() const;
  ~Init() = default;

  void static GLframebuffer_size_callback(GLFWwindow *window, int width,
                                          int height) {
    glViewport(0, 0, width, height);
  }
  /* ~Init(); */
};
extern std::unique_ptr<Uniforms> Uniforms_list;

// ###################################################################################################
//                                 Defines
//  ###################################################################################################

// ###################################################################################################
//                                 Logging
//  ###################################################################################################

} // namespace Engine
