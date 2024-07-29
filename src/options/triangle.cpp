
#include "triangle.h"
#include "init.h"
#include "Window.h"
#include "Interfaces/includes.h"
#include "../../include/renderer.h"
#include <memory>
 #include <iostream> 
namespace Engine{

  Triangle::Triangle(){

    //initialize OpenGL first
    Engine::Init init;
    init.InitOpenGL();


    Engine::GLwindow = std::make_unique<Engine::GLWindow>(glfwCreateWindow(800, 800, "window", nullptr, nullptr));

    glfwMakeContextCurrent(Engine::GLwindow->window);

    init.InitGlad();
    GLshader = std::make_unique<Shader>("/home/uttkarsh/NewOpenGL/shaders/vertex.shader", "/home/uttkarsh/NewOpenGL/shaders/fragment.shader"); //give absolute paths as it is required by a c++ function;


    GLfloat vertices[]={
            -0.5f,  0.5f, 0.0f,  // Top-left
            0.5f,  0.5f, 0.0f,  // Top-right
            0.5f, -0.5f, 0.0f,  // Bottom-right
            -0.5f, -0.5f, 0.0f   // Bottom-left 
    };
    GLuint indices[]={
        0, 1, 2,
        2, 3, 0
    };


    vertexArrayObject = std::make_unique<VAO>();
    vertexArrayObject->Bind();

    Layout.PushFloat(3, 3);

    VBO vbo(vertices, sizeof(vertices));
    vbo.Bind();


    //i had passed EBO(indices,size...) instead of just indices,sizeof...
    ebo = std::make_unique<EBO>(indices,sizeof(indices)/sizeof(indices[0]));
    ebo->Bind();

    vertexArrayObject->addBuffer(vbo, Layout);
    vertexArrayObject->Unbind();

    /* vbo.Unbind(); */


    glfwSetFramebufferSizeCallback(Engine::GLwindow->window, Engine::Init::GLframebuffer_size_callback);
    /* GLshader->UseUniformNumber("u_color", 0.0f, 0.0f, 0.25f, 1.0f); */
    
    renderer = std::make_unique<Renderer>();
  }

  void Triangle::Render() const{

    while(!glfwWindowShouldClose(Engine::GLwindow->window)){
        glClearColor(0.0, 0.0, 0.1, 0.1);
        glClear(GL_COLOR_BUFFER_BIT);

        GLshader->activate();
        vertexArrayObject->Bind();
        ebo->Bind();

        // Render the square
        renderer->render(6);

        glfwSwapBuffers(Engine::GLwindow->window);
        glfwPollEvents();
    }
    ebo->UnBind();
    vertexArrayObject->Unbind();
    GLshader->Delete();
    glfwDestroyWindow(Engine::GLwindow->window);
    glfwTerminate();
  }

  std::unique_ptr<Renderer> renderer;
  std::unique_ptr<Shader> GLshader;
  std::unique_ptr<VAO> vertexArrayObject;
  std::unique_ptr<EBO> ebo;

}
