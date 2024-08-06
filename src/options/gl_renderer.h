#pragma once
#include "../../include/renderer.h"
#include "../../include/shaderClass.h"
#include "BumpAllocator.h"
#include "logger.h"

namespace Engine {

class GLRenderer{
  public:
    bool gl_init(BumpAllocator * transientStorage);
    void gl_render();

};
extern std::unique_ptr<EBO> ebo;
extern std::unique_ptr<Shader> GLshader;
extern std::unique_ptr<Renderer> renderer;
extern std::unique_ptr<VAO> vertexArrayObject;
extern layout Layout;
extern std::unique_ptr<allocator> Allocator;
} // namespace Engine
