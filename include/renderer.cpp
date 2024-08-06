#include "renderer.h"
#include <memory>


void Renderer::Draw(std::unique_ptr<VAO> vao,EBO& ebo,std::unique_ptr<Shader> shader) {
  shader->activate();
  vao->Bind();
  ebo.Bind();
  glDrawElements(GL_TRIANGLES,ebo.count,GL_UNSIGNED_INT,nullptr);
}


void Renderer::Draw(std::unique_ptr<VAO> vao,std::unique_ptr<EBO> ebo,std::unique_ptr<Shader> shader){
  /* shader->activate(); */
  /* vao->Bind(); */
  /* ebo->Bind(); */
  /* glDrawElements(GL_TRIANGLES,ebo->count,GL_UNSIGNED_INT,nullptr); */
  glDrawArrays(GL_TRIANGLES, 0, ebo->count);
}


void Renderer::render(int count) const{
  /* glDrawArrays(GL_TRIANGLES, 0, count); */
  glDrawElements(GL_TRIANGLES,count,GL_UNSIGNED_INT,0);
}


void Renderer::ClearBuffer(){
  glClear(GL_COLOR_BUFFER_BIT);
}
Renderer::~Renderer(){
  
}
