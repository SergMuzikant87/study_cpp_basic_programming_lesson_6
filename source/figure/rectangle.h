#pragma once

#include "parallelogram.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Класс "Прямоугольник"
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Rectangle : public Parallelogram
{
    public:
        Rectangle(void);
        Rectangle(float a, float b);
        Rectangle(const Rectangle & figure_copyed);
        Rectangle & operator= (const Rectangle & figure_copyed);

        bool is_correct(void) const override;
};