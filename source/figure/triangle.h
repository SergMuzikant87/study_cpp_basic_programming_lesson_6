#pragma once

#include "figure.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Класс  "Треугольник"
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Triangle : public Figure
{
    protected:
        bool __angles_summ_is_correct(void) const override;
        float __get_angles_summ_correct(void) const override;
        
    
    public:
        Triangle(void);
        Triangle(float a, float b, float c, float A, float B, float C);
        Triangle(float a, float b, float c, float A, float B);
        Triangle(const Triangle & figure_copyed);
        Triangle & operator= (const Triangle & figure_copyed);
        
        bool is_correct(void) const override;

};
