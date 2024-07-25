#pragma once

#include "../external/glad/include/glad/glad.h"
#include "../external/glfw/include/GLFW/glfw3.h"
#include <iostream>

class Texture {
private:
  unsigned int ID;
  std::string m_FilePath;
  unsigned char *m_LocalBuffer;
  int width, height, BPP;

public:
  Texture(const std::string &path);
  ~Texture();
  void Bind(unsigned int slot = 0) const;
  void UnBind() const;

  inline int GetWidth() const { return width; }
  inline int GetHeight() const { return height; }
};
