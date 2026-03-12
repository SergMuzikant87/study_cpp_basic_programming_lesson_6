#pragma once

#include "triangle.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Класс "Равнобедренный треугольник"
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Triangle_Right_Angled : public Triangle
{
    public:
        Triangle_Right_Angled(void);
        Triangle_Right_Angled(float a, float b, float A, float B);
        Triangle_Right_Angled(const Triangle_Right_Angled & figure_copyed);
        Triangle_Right_Angled & operator= (const Triangle_Right_Angled & figure_copyed);

        bool is_correct(void) const override;

};
