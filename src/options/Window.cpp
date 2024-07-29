#include "Window.h"
#include <stdio.h>

namespace Engine {
  
  GLWindow::GLWindow(GLFWwindow* window1):window(window1){
    if(!window){
        perror("error creating the window");
    }
  }
  std::unique_ptr<GLWindow> GLwindow;
}
