/* #ifdef SHAPE_H */
/* #define SHAPE_H */
#pragma once

namespace Engine{

    class Shape{
        /* virtual ~Shape(){}; */
        virtual void Render() const =0;
    };

}



/* #endif */
