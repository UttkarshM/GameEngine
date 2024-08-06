#pragma once

#include "../../include/shaderClass.h"
#include "Interfaces/includes.h"
#include "Interfaces/shape.h"
/* #include "../../include/EBO.h" */
#include "../../include/renderer.h"
#include "../../include/texture.h"
#include "BumpAllocator.h"
#include <memory>
namespace Engine {

class Triangle : public Shape {
public:
  Triangle();
  void Render() const override;
  ~Triangle();
};

struct Texturer{
Texture t1;
};
extern std::unique_ptr<EBO> ebo;
extern std::unique_ptr<Shader> GLshader;
extern std::unique_ptr<Renderer> renderer;
extern std::unique_ptr<VAO> vertexArrayObject;
extern layout Layout;
extern std::unique_ptr<allocator> Allocator;
extern std::unique_ptr<Texturer> GLTexturer2;
}; // namespace Engine
