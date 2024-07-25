#pragma once

#include "../external/glad/include/glad/glad.h"
#include "../external/glfw/include/GLFW/glfw3.h"
/* #include <iostream> */

class VBO {
private:
  GLuint ID;

public:
  VBO(const void *data, GLuint size);
  ~VBO();
  void Bind() const;
  void Unbind() const;
};
