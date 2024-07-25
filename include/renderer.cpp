#include "renderer.h"
#include <memory>

void Renderer::Draw(std::unique_ptr<VAO> vao,EBO& ebo,std::unique_ptr<Shader> shader) {
  shader->activate();
  vao->Bind();
  ebo.Bind();
  glDrawElements(GL_TRIANGLES,ebo.count,GL_UNSIGNED_INT,nullptr);
}
void Renderer::ClearBuffer(){
  glClear(GL_COLOR_BUFFER_BIT);
}


