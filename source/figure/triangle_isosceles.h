#pragma once

#include "triangle.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Класс "Прямоугольный треугольник"
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Triangle_Isosceles : public Triangle
{
    protected:
        float __set_edge_C(void);

    public:
        Triangle_Isosceles(void);
        Triangle_Isosceles(float a, float b, float A, float B);
        Triangle_Isosceles(float a, float b, float A);
        Triangle_Isosceles(const Triangle_Isosceles & figure_copyed);
        Triangle_Isosceles & operator= (const Triangle_Isosceles & figure_copyed);

        bool is_correct(void) const override;
};
