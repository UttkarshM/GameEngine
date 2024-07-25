#include "VAO.h"
#include "renderer.h"


VAO::VAO(){
    glGenVertexArrays(1, &ID);
}
void VAO::deleteV() const{
    glDeleteVertexArrays(1, &ID);
}

void VAO::addBuffer(const VBO& VBO, const layout &layout){
    Bind();
    VBO.Bind();
    unsigned int offset = 0;
    const auto& elements = layout.GetElements();
    int total=0;
    for( unsigned int i=0; i < elements.size(); i++){
        const auto& element = elements[i];
        
        glVertexAttribPointer(i, element.count, element.type, element.normalised, layout.GetStride(), (const void*)offset);
        glEnableVertexAttribArray(i);



/*glVertexAttribPointer is a function in OpenGL that specifies the format and location of vertex attribute data in a vertex buffer object (VBO).
 This function is essential for telling OpenGL how to interpret the vertex data that will be used in the rendering pipeline.
        std::cout<<element.count<<std::endl;
  */
        /* std::cout<<element.count * VertexBufferElements::GetSizeofType(element.type)<<std::endl; */
        offset += element.count * VertexBufferElements::GetSizeofType(element.type );

        /* std::cout<<layout.GetStride()<<std::endl; */
    /* std::cout<<offset<<std::endl; */
    }
}
void VAO::Bind() const {
    glBindVertexArray( ID);
}
void VAO::Unbind() const{
    glBindVertexArray( 0);
}
