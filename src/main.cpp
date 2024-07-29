#include "options/triangle.h"
/* #include "../external/glad/include/glad/glad.h" */
/* #include "../external/glfw/include/GLFW/glfw3.h" */

int main(){
    Engine::Triangle t1;
    t1.Render();
    return 0;
}
/* #include <glad/glad.h> */
/* #include <GLFW/glfw3.h> */
/* #include <iostream> */
/**/
/* // Define the size of the window */
/* const GLuint WIDTH = 800, HEIGHT = 600; */
/**/
/* // Vertex data for a square */
/* GLfloat vertices[] = { */
/*     // Positions        */
/*     -0.5f,  0.5f, 0.0f,  // Top-left */
/*      0.5f,  0.5f, 0.0f,  // Top-right */
/*      0.5f, -0.5f, 0.0f,  // Bottom-right */
/*     -0.5f, -0.5f, 0.0f   // Bottom-left */
/* }; */
/**/
/* // Indices for drawing two triangles */
/* GLuint indices[] = { */
/*     0, 1, 2, // First triangle */
/*     2, 3, 0  // Second triangle */
/* }; */
/**/
/* void framebuffer_size_callback(GLFWwindow* window, int width, int height) { */
/*     glViewport(0, 0, width, height); */
/* } */
/**/
/* int main() { */
/*     // Initialize GLFW */
/*     if (!glfwInit()) { */
/*         std::cerr << "Failed to initialize GLFW" << std::endl; */
/*         return -1; */
/*     } */
/**/
/*     // Set GLFW context version and profile */
/*     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); */
/*     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); */
/*     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); */
/**/
/*     // Create GLFW window */
/*     GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Square", nullptr, nullptr); */
/*     if (!window) { */
/*         std::cerr << "Failed to create GLFW window" << std::endl; */
/*         glfwTerminate(); */
/*         return -1; */
/*     } */
/*     glfwMakeContextCurrent(window); */
/*     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); */
/**/
/*     // Initialize GLAD */
/*     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { */
/*         std::cerr << "Failed to initialize GLAD" << std::endl; */
/*         return -1; */
/*     } */
/**/
/*     // Vertex Shader */
/*     const char* vertexShaderSource = R"( */
/*         #version 330 core */
/*         layout (location = 0) in vec3 aPos; */
/*         void main() { */
/*             gl_Position = vec4(aPos, 1.0); */
/*         } */
/*     )"; */
/**/
/*     // Fragment Shader */
/*     const char* fragmentShaderSource = R"( */
/*         #version 330 core */
/*         out vec4 FragColor; */
/*         void main() { */
/*             FragColor = vec4(0.0, 0.5, 0.0, 1.0); */
/*         } */
/*     )"; */
/**/
/*     // Compile Vertex Shader */
/*     GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); */
/*     glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr); */
/*     glCompileShader(vertexShader); */
/**/
/*     // Check Vertex Shader Compilation */
/*     GLint success; */
/*     GLchar infoLog[512]; */
/*     glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); */
/*     if (!success) { */
/*         glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog); */
/*         std::cerr << "Vertex Shader Compilation Failed: " << infoLog << std::endl; */
/*     } */
/**/
/*     // Compile Fragment Shader */
/*     GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); */
/*     glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr); */
/*     glCompileShader(fragmentShader); */
/**/
/*     // Check Fragment Shader Compilation */
/*     glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success); */
/*     if (!success) { */
/*         glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog); */
/*         std::cerr << "Fragment Shader Compilation Failed: " << infoLog << std::endl; */
/*     } */
/**/
/*     // Shader Program */
/*     GLuint shaderProgram = glCreateProgram(); */
/*     glAttachShader(shaderProgram, vertexShader); */
/*     glAttachShader(shaderProgram, fragmentShader); */
/*     glLinkProgram(shaderProgram); */
/**/
/*     // Check Shader Program Linking */
/*     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success); */
/*     if (!success) { */
/*         glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog); */
/*         std::cerr << "Shader Program Linking Failed: " << infoLog << std::endl; */
/*     } */
/**/
/*     // Clean up shaders */
/*     glDeleteShader(vertexShader); */
/*     glDeleteShader(fragmentShader); */
/**/
/*     // Set up VAO, VBO, and EBO */
/*     GLuint VAO, VBO, EBO; */
/*     glGenVertexArrays(1, &VAO); */
/*     glGenBuffers(1, &VBO); */
/*     glGenBuffers(1, &EBO); */
/**/
/*     glBindVertexArray(VAO); */
/**/
/*     glBindBuffer(GL_ARRAY_BUFFER, VBO); */
/*     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); */
/**/
/*     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); */
/*     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); */
/**/
/*     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0); */
/*     glEnableVertexAttribArray(0); */
/**/
/*     glBindBuffer(GL_ARRAY_BUFFER, 0);  */
/*     glBindVertexArray(0);  */
/**/
/*     // Render loop */
/*     while (!glfwWindowShouldClose(window)) { */
/*         glClear(GL_COLOR_BUFFER_BIT); */
/**/
/*         // Draw Square */
/*         glUseProgram(shaderProgram); */
/*         glBindVertexArray(VAO); */
/*         glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); */
/**/
/*         glfwSwapBuffers(window); */
/*         glfwPollEvents(); */
/*     } */
/**/
/*     // Clean up */
/*     glDeleteVertexArrays(1, &VAO); */
/*     glDeleteBuffers(1, &VBO); */
/*     glDeleteBuffers(1, &EBO); */
/*     glDeleteProgram(shaderProgram); */
/**/
/*     glfwTerminate(); */
/*     return 0; */
/* } */
