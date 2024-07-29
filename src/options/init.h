/* #ifdef INIT_H */
/* #define INIT_H */
#pragma once
#include <iostream>
#include <memory>
#include "../../include/shaderClass.h"

#include "../../external/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>
namespace Engine{
class Init{
    public:
        Init()=default;
        void InitOpenGL() const;
        void InitGlad() const;
        void GLframebuffer_size_callback() const;
        ~Init()=default;
        
    void static GLframebuffer_size_callback(GLFWwindow* window, int width, int height) {
       glViewport(0, 0, width, height);
    }
        /* ~Init(); */
};
  /* extern std::unique_ptr<GLWindow> window; */
    /* const char *glsl_version = "#version 130"; */

}

