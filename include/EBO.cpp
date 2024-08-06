#include"EBO.h"

EBO::EBO(const unsigned int* data,unsigned int count)
:count(count)
{
    glGenBuffers(1,&ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(GLuint),data,GL_STATIC_DRAW);
}
EBO::~EBO(){
  UnBind();
    glDeleteBuffers(1,&ID);
}
void EBO::Bind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ID);
}
void EBO::UnBind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
} 
