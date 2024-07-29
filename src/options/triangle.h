#pragma once

#include "Interfaces/includes.h"
#include "Interfaces/shape.h"
#include "../../include/shaderClass.h"
/* #include "../../include/EBO.h" */
#include "../../include/renderer.h"
#include <memory>

namespace Engine{

    class Triangle: public Shape{
        public:
            Triangle();
            void Render() const override;
    };

    extern std::unique_ptr<EBO> ebo;
    extern std::unique_ptr<Shader> GLshader;
    extern std::unique_ptr<Renderer> renderer;
    extern std::unique_ptr<VAO> vertexArrayObject;
    extern layout Layout;
};
