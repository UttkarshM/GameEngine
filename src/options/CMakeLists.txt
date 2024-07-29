set(
  Options_files
  init.cpp 
  triangle.cpp
  Window.cpp
  # test.cpp
)
set(
  Interface_files
  Interfaces/includes.h
  Interfaces/init.h
  Interfaces/shape.h
)

add_library(Options STATIC 
  ${Options_files}
  )

include_directories(${CMAKE_CURRENT_DIR})

target_include_directories(Options PUBLIC ${PROJECT_SOURCE_DIR}/external/glfw/include ${PROJECT_SOURCE_DIR}/external/glad/include 
  ${PROJECT_SOURCE_DIR}/include/
  )

target_link_libraries(Options PRIVATE glad glfw includes glm)

