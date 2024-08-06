#include "init.h"
/* #include "../../include/shaderClass.h" */
#include "../../external/glad/include/glad/glad.h"
#include "../../external/glfw/include/GLFW/glfw3.h"
#include "../../include/VAO.h"
#include "../../include/shaderClass.h"
// #include "BumpAllocator.h"
#include "triangle.h"
#include <cerrno>
#include <memory>
#include <stdio.h>

namespace Engine {
std::unique_ptr<Shader> Shader;
std::unique_ptr<VAO> VertexArrayObject;
layout Layout;

// specifying the viewport so that we can both declare it and initialize the
// glad with __interface It

void Init::InitOpenGL() const {

  if (!glfwInit())
    perror("error initializing glfw. ");

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

// initialize glfw before glad.
// https://stackoverflow.com/questions/63120602/why-should-you-use-an-external-opengl-loader-function-instead-of-glads-built-in
// -why we load glad in this way.
void Init::InitGlad() const {
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    perror("error in initializing glad");
}

bool gl_init() { return true; }

} // namespace Engine
