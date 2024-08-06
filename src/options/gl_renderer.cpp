#include "gl_renderer.h"
#include "BumpAllocator.h"
#include "../../external/stb/stb_image.h"
#include "../../include/renderer.h"
// #include "BumpAllocator.h"
#include "Interfaces/includes.h"
#include "Window.h"
#include "init.h"
#include "logger.h"
// #include "logger.h"
#include <memory>
/* #include <iostream>  */

namespace Engine {

bool GLRenderer::gl_init(BumpAllocator *transientStorage) {
  Init init;
  init.InitOpenGL();
  init.InitGlad();

  Engine::GLwindow = std::make_unique<Engine::GLWindow>(
      glfwCreateWindow(800, 800, "window", nullptr, nullptr));
 
  glfwMakeContextCurrent(Engine::GLwindow->window);


  int fileSize = 0;

  GLshader = std::make_unique<Shader>(
      "/home/uttkarsh/NewOpenGL/assets/shaders/quad.vertex",
      "/home/uttkarsh/NewOpenGL/assets/shaders/quad.frag"); // give
                                                                  // absolute
                                                                  // paths as it
                                                                  // is required
                                                                  // by a c++
                                                                  // function;

  int vertexShader = get_file_size("/home/uttkarsh/NewOpenGL/assets/shaders/vertex.shader"); EN_TRACE("loaded vertex texture ");
  int fragShader = get_file_size("/home/uttkarsh/NewOpenGL/assets/shaders/fragment.shader"); EN_TRACE("loaded fragment texture ");

  if (!vertexShader || !fragShader) {
    EN_ERROR("Failed to load shaders");
    return false;
  }

  // This has to be done, otherwise OpenGL will not draw anything
  GLuint VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  // Depth Tesing
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_GREATER);

  // Use Program
  glfwSetFramebufferSizeCallback(Engine::GLwindow->window,
                                 Engine::Init::GLframebuffer_size_callback);
  GLshader->activate();
  return true;
}

void GLRenderer::gl_render() {
  glClearColor(119.0f / 255.0f, 33.0f / 255.0f, 111.0f / 255.0f, 1.0f);
  glClearDepth(0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glDrawArrays(GL_TRIANGLES, 0, 6);
}
std::unique_ptr<Renderer> renderer;
std::unique_ptr<Shader> GLshader;
std::unique_ptr<VAO> vertexArrayObject;
std::unique_ptr<EBO> ebo;
std::unique_ptr<allocator> Allocator;
} // namespace Engine
