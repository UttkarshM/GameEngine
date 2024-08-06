#include "Window.h"
#include <stdio.h>

namespace Engine {

GLWindow::GLWindow(GLFWwindow *window1) : window(window1) {
  if (!window) {
    EN_ERROR("Failed to create a window");
    perror("error creating the window");
  }
  EN_TRACE("created the window successfully");
}
GLWindow::~GLWindow() { glfwDestroyWindow(window); }
std::unique_ptr<GLWindow> GLwindow;
} // namespace Engine
