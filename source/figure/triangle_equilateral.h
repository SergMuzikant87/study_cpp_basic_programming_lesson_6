#pragma once

#include "triangle_right_angled.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Класс "Равносторонний треугольник"
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Triangle_Equilateral : public Triangle_Right_Angled
{
    public:
        Triangle_Equilateral(void);
        Triangle_Equilateral(float a);
        Triangle_Equilateral(const Triangle_Equilateral & figure_copyed);
        Triangle_Equilateral & operator= (const Triangle_Equilateral & figure_copyed);

        bool is_correct(void) const override;
};
