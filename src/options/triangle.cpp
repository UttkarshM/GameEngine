
#include "triangle.h"
#include "../../external/stb/stb_image.h"
#include "../../include/renderer.h"
// #include "BumpAllocator.h"
#include "Interfaces/includes.h"
#include "Window.h"
#include "init.h"
#include "logger.h"
// #include "logger.h"
#include <memory>
#include "../../include/texture.h"
/* #include <iostream>  */
namespace Engine {

Triangle::Triangle() {

  // initialize OpenGL first
  Engine::Init init;
  init.InitOpenGL();
  EN_TRACE("Initialize OpenGL");

  Engine::GLwindow = std::make_unique<Engine::GLWindow>(
      glfwCreateWindow(800, 800, "window", nullptr, nullptr));

  glfwMakeContextCurrent(Engine::GLwindow->window);

  init.InitGlad();
  EN_TRACE("Initialized Glad");

  GLshader = std::make_unique<Shader>(
      "/home/uttkarsh/NewOpenGL/assets/shaders/vertex.shader",
      "/home/uttkarsh/NewOpenGL/assets/shaders/fragment.shader"); // give
                                                                  // absolute
                                                                  // paths as it
                                                                  // is required
                                                                  // by a c++
                                                                  // function;
  Texture t1("/home/uttkarsh/NewOpenGL/assets/textures/squares.jpg");
  t1.Bind(0);
  /* Engine::GLTexturer = ; */
  /* Texture Tex("/home/uttkarsh/NewOpenGL/assets/textures/squares.jpg"); */
  /* GLTexturer2->t1 = Tex; */
  /* GLTexturer->t1=t1; */
  GLshader->UseUniform1i("u_Texture",0);

  int fileSize = 0;

  char *vertexShader =
      read_file("/home/uttkarsh/NewOpenGL/assets/shaders/vertex.shader",
                &fileSize, &Allocator->allocator);
  EN_TRACE("loaded vertex texture ");

  char *fragShader =
      read_file("/home/uttkarsh/NewOpenGL/assets/shaders/fragment.shader",
                &fileSize, &Allocator->allocator);

  EN_TRACE("loaded fragment texture ");

  GLfloat vertices[] = {
      -0.25f, 0.25f, 0.0f,1.0f,     // Top-left
      0.25f,  0.25f, 1.0f,1.0f,  // Top-right
      0.25f,  -0.25f,0.0f,0.0f,  // Bottom-right
      -0.25f, -0.25f,1.0f,0.0f   // Bottom-left
  };
  GLuint indices[] = {0, 1, 2, 2, 3, 0};

  vertexArrayObject = std::make_unique<VAO>();
  vertexArrayObject->Bind();
  EN_TRACE("Vertex Array Initialized");

  Layout.PushFloat(2, 2);
  Layout.PushFloat(2,2);
  EN_TRACE("Layout initialized")

  VBO vbo(vertices, sizeof(vertices));
  vbo.Bind();

  EN_TRACE("VBO initialized");

  // i had passed EBO(indices,size...) instead of just indices,sizeof...
  ebo = std::make_unique<EBO>(indices, sizeof(indices) / sizeof(indices[0]));
  ebo->Bind();

  EN_TRACE("EBO initialized");

  vertexArrayObject->addBuffer(vbo, Layout);
  vertexArrayObject->Unbind();

  /* vbo.Unbind(); */

  glfwSetFramebufferSizeCallback(Engine::GLwindow->window,
                                 Engine::Init::GLframebuffer_size_callback);
  GLshader->UseUniformNumber("color", 1.0f, 1.0f, 0.1f, 1.0f);
  EN_TRACE("Uniform Initialized");
  renderer = std::make_unique<Renderer>();
  // EN_ASSERT(false, "Assertion not hit");
}

void Triangle::Render() const {
  Texture t1("/home/uttkarsh/NewOpenGL/assets/textures/squares.jpg");
  t1.Bind(0);

  while (!glfwWindowShouldClose(Engine::GLwindow->window)) {
    glClearColor(0.0, 0.0, 0.1, 0.1);
    glClear(GL_COLOR_BUFFER_BIT);
    GLshader->activate();
    GLshader->UseUniformNumber("color", 1.0f, 1.0f, 0.1f, 1.0f);
    /* GLshader->UseUniformNumber("color", 0.0f, 1.0f, 0.1f, 1.0f); */
    GLshader->UseUniform1i("u_Texture",0);
    t1.Bind(0);
    /* GLTexturer2->t1.Bind(0); */
      

    vertexArrayObject->Bind();
    ebo->Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    // Render the square
    glfwSwapBuffers(Engine::GLwindow->window);
    glfwPollEvents();
  }
}

Triangle::~Triangle() {
  ebo->UnBind();
  vertexArrayObject->Unbind();
  GLshader->Delete();

  glfwDestroyWindow(Engine::GLwindow->window);
  glfwTerminate();
  EN_TRACE("terminated");
}

std::unique_ptr<Renderer> renderer;
std::unique_ptr<Shader> GLshader;
std::unique_ptr<VAO> vertexArrayObject;
std::unique_ptr<EBO> ebo;
std::unique_ptr<allocator> Allocator;

} // namespace Engine
