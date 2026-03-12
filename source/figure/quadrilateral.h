#pragma once

#include "figure.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Класс "Четырёхугольнгик"
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Quadrilateral : public Figure
{
    protected:
        bool __angles_summ_is_correct(void) const override;
        float __get_angles_summ_correct(void) const override;

    public:
        Quadrilateral(void);
        Quadrilateral(float a, float b, float c, float d, float A, float B, float C, float D);
        Quadrilateral(float a, float b, float c, float d, float A, float B, float C);
        Quadrilateral(const Quadrilateral & figure_copyed);
        Quadrilateral & operator= (const Quadrilateral & figure_copyed);


        bool is_correct(void) const override;
};
