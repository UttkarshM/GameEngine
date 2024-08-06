#include "texture.h"
#include <GL/gl.h>
#include <GL/glext.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const std::string& path)
:ID(0),m_FilePath(path),m_LocalBuffer(nullptr),width(0),height(0),BPP(0)
{
  stbi_set_flip_vertically_on_load(1);
  m_LocalBuffer = stbi_load(path.c_str(),&width,&height,&BPP,4);// 4 color channels
                                                                //
  if(!m_LocalBuffer){
    std::cout<<"failed to load the texture"<<std::endl;
  }
  /* std::cout<<m_LocalBuffer<<std::endl; */

  glGenTextures(1,&ID);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D,ID);

  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

  glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width,height,0,GL_RGBA,GL_UNSIGNED_BYTE,m_LocalBuffer);
  glGenerateMipmap(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,0);

  if(m_LocalBuffer){
   stbi_image_free(m_LocalBuffer);
  }
}
Texture::~Texture(){
  glDeleteTextures(1,&ID);
}
void Texture::Bind(unsigned int slot) const{

  glActiveTexture(GL_TEXTURE0+slot);
  glBindTexture(GL_TEXTURE_2D,ID);
}
void Texture::UnBind() const{
  glBindTexture(GL_TEXTURE_2D,0);
}

