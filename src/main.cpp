#include "options/BumpAllocator.h"
#include "options/triangle.h"
/* #include "options/gl_renderer.h" */
int main() {

  Engine::Allocator = std::make_unique<Engine::allocator>();
  Engine::BumpAllocator transientStorage = Engine::make_bump_allocator(MB(50));

  Engine::Allocator->allocator = transientStorage;

  /* Engine::GLRenderer render; */
  /* render.gl_init(&transientStorage); */
  /* render.gl_render(); */
  Engine::Triangle t1;
  t1.Render();
  return 0;
}
