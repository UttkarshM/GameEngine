#pragma once

#include "../external/glad/include/glad/glad.h"
#include "../external/glfw/include/GLFW/glfw3.h"
#include "EBO.h"
#include "VAO.h"
#include "shaderClass.h"
#include <memory>

class Renderer {
public:
  void Draw(std::unique_ptr<VAO> vao, EBO &ebo, std::unique_ptr<Shader> shader);
  void Draw(std::unique_ptr<VAO> vao,std::unique_ptr<EBO>ebo,std::unique_ptr<Shader>GLshader);
  void render(int count) const;
  void ClearBuffer();
};
