#include <cstdio>
#include <iostream>
#include <memory>
#include <utility>
#include "../include/renderer.h"
#include "../include/shaderClass.h"
#include "../include/VBO.h"
#include "../include/VAO.h"
#include "../external/glfw/include/GLFW/glfw3.h"
#include "../external/glad/include/glad/glad.h"



void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main(){

    const char *glsl_version = "#version 130";
    if(!glfwInit()){
        perror("error initializing glfw");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(900, 900, "title", nullptr, nullptr);
    if(!window){
        perror("error creating the window");
        return -1;
    }

    glfwMakeContextCurrent(window);
    
    //initialize glfw before glad.
    //https://stackoverflow.com/questions/63120602/why-should-you-use-an-external-opengl-loader-function-instead-of-glads-built-in -why we load glad in this way.
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        perror("error in initializing glad");
        return -1;
    }

    GLfloat vertices[]={
        -0.5/1.5f, -0.0f, 0.0f,
        0.5/1.5f, 0.0f, 0.0f,
        0.0f, 0.5/1.5f, 0.0f
    };
    GLuint indices[]={
        0, 1, 2
    };
    std::unique_ptr<Shader> shader = std::make_unique<Shader>("/home/uttkarsh/NewOpenGL/shaders/vertex.shader", "/home/uttkarsh/NewOpenGL/shaders/fragment.shader"); //give absolute paths as it is required by a c++ function;
    // ("../shaders/vertex.shader", "../shaders/fragment.shader");
    Renderer renderer;


    std::unique_ptr<VAO> vertexArray = std::make_unique<VAO>();
    vertexArray->Bind();

    layout Layout;
    Layout.PushFloat(3, 3);

    VBO vbo(vertices, sizeof(vertices));
    vbo.Bind();
    EBO ebo(indices,3);
    ebo.Bind();

    vertexArray->addBuffer(vbo, Layout);
    vertexArray->Unbind();
    
    vbo.Unbind();

    glViewport(0,0,800,800);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // shader->UseUniformNumber("tricolor", , float v1, float v2, float v3)
    shader->UseUniformNumber("u_color", 1.0f, 0.0f, 0.25f, 1.0f);

    while(!glfwWindowShouldClose( window)){
        glClearColor(0.0, 0.0, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        shader->activate();
        vertexArray->Bind();
        renderer.ClearBuffer();
        ebo.Bind();
        // renderer.Draw(std::move(vertexArray), ebo, std::move(shader));
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // std::cout<<"bot boy";
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    ebo.UnBind();
    vertexArray->Unbind();
    shader->Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
