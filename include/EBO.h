#include "../external/glad/include/glad/glad.h"
#include "../external/glfw/include/GLFW/glfw3.h"

class EBO {
public:
  GLuint ID, count;
  EBO(const unsigned int *data, unsigned int count);
  ~EBO();
  void Bind();
  void UnBind();
  inline int GetCount() { return count; };
};
