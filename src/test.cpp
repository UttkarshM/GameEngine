#include "options/BumpAllocator.h"
#include "options/logger.h"
#include "options/triangle.h"
#include <iostream>
using namespace std;

int main() {

  Engine::Allocator = std::make_unique<Engine::allocator>();
  Engine::BumpAllocator transientStorage = Engine::make_bump_allocator(MB(50));

  Engine::Allocator->allocator = transientStorage;
  int fileSize;
  cout << Engine::file_exists(
              "/home/uttkarsh/NewOpenGL/assets/shaders/vertex.shader")
       << endl;
  cout << Engine::get_file_size(
      "/home/uttkarsh/NewOpenGL/assets/shaders/vertex.shader");
  char buffer[10000];
  char *vertexShader =
      Engine::read_file("/home/uttkarsh/NewOpenGL/assets/shaders/vertex.shader",
                        &fileSize, buffer);
  cout << vertexShader << endl;
  //   char *fragShader = Engine::read_file(
  //       "/home/uttkarsh/NewOpenGL/assets/shaders/fragment.shader",
  //       &fileSize, &transientStorage);

  //   cout << vertexShader << endl;
  //   cout << fragShader << endl;
  return 0;
}