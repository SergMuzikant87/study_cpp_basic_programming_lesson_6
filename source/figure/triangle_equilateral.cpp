#include "triangle_equilateral.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Методы класса "Равносторонний треугольник"
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////

Triangle_Equilateral::Triangle_Equilateral(void) : Triangle_Right_Angled::Triangle_Right_Angled(0.0, 0.0, 60.0, 60.0)
{
    __set_name("Равносторонний треугольник");
}

Triangle_Equilateral::Triangle_Equilateral(float a) : Triangle_Right_Angled::Triangle_Right_Angled(a, a, 60.0, 60.0)
{
    __set_name("Равносторонний треугольник");
}

Triangle_Equilateral::Triangle_Equilateral(const Triangle_Equilateral & figure_copyed) : Triangle_Right_Angled(figure_copyed)
{

};

Triangle_Equilateral & Triangle_Equilateral::operator= (const Triangle_Equilateral & figure_copyed)
{
    ::Triangle_Right_Angled::operator= (figure_copyed);
    return *this;
};

bool Triangle_Equilateral::is_correct(void) const 
{
    float A = get_angle(angles_indexes_t::A);
    float B = get_angle(angles_indexes_t::B);
    float C = get_angle(angles_indexes_t::C);
    const float correct_angle = 60.0;
    return Triangle_Right_Angled::is_correct() && Triangle_Equilateral::__float_is_equal(A, correct_angle) && Triangle_Equilateral::__float_is_equal(B, correct_angle) && Triangle_Equilateral::__float_is_equal(C, correct_angle);
}