#pragma once
/* #include <GL/gl.h> */
#include "../external/glad/include/glad/glad.h"
/* #include "../external/glfw/include/GLFW/glfw3.h" */
#include <vector>
struct VertexBufferElements {
  unsigned int count;
  unsigned int type;
  unsigned int normalised;
  static unsigned int GetSizeofType(unsigned int type) {
    switch (type) {
    case GL_FLOAT:
      return 4;
    case GL_UNSIGNED_INT:
      return 4;
    case GL_UNSIGNED_BYTE:
      return 1;
    }

    return 0;
  }
};

class layout {
private:
  unsigned int m_Stride;
  std::vector<VertexBufferElements> m_Elements;

public:
  layout() : m_Stride(0){};

  // template<typename T>
  // void Push(int count){
  //     static_assert("false");
  // }
  void PushFloat(unsigned int count,unsigned int size) {
    m_Elements.push_back({count, GL_FLOAT, GL_FALSE});
    m_Stride += size * VertexBufferElements::GetSizeofType(GL_FLOAT);
  }
  void PushInt(unsigned int count,unsigned int size) {
    m_Elements.push_back({count, GL_UNSIGNED_INT, GL_FALSE});
    m_Stride += size * VertexBufferElements::GetSizeofType(GL_UNSIGNED_INT);
  }
  void PushChar(unsigned int count,unsigned int size) {
    m_Elements.push_back({count, GL_UNSIGNED_BYTE, GL_TRUE});
    m_Stride += size * VertexBufferElements::GetSizeofType(GL_UNSIGNED_BYTE);
  }
  inline std::vector<VertexBufferElements> GetElements() const {
    return m_Elements;
  }
  inline unsigned int GetStride() const { return m_Stride; }
};
