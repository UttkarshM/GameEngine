#pragma once
#include "../../external/glad/include/glad/glad.h"
#include "../../external/glfw/include/GLFW/glfw3.h"
#include <memory>

namespace Engine{

  class GLWindow{
    public:
      GLFWwindow* window;
      GLWindow(GLFWwindow* window1);
  };
  extern std::unique_ptr<GLWindow> GLwindow;

};
