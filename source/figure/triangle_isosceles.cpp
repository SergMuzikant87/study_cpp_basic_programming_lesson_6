
#include "triangle_isosceles.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Методы класса "Прямоугольный треугольник"
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

Triangle_Isosceles::Triangle_Isosceles(void) : Triangle::Triangle(0, 0, 0, 0, 0, 90)
{
    __set_name("Прямоугольный треугольник");
    __set_edge_C();
}

Triangle_Isosceles::Triangle_Isosceles(float a, float b, float A, float B) : Triangle::Triangle(a, b, 0, A, B, 90)
{
    __set_name("Прямоугольный треугольник");
    __set_edge_C();
}

Triangle_Isosceles::Triangle_Isosceles(float a, float b, float A) : Triangle_Isosceles::Triangle_Isosceles(a, b, A, __float_limmit((180.0 - 90.0 - A), 0.001, 89.999))
{

}

Triangle_Isosceles::Triangle_Isosceles(const Triangle_Isosceles & figure_copyed) : Triangle(figure_copyed)
{

}

Triangle_Isosceles & Triangle_Isosceles::operator= (const Triangle_Isosceles & figure_copyed)
{
    ::Triangle::operator= (figure_copyed);
    return *this;
}

float Triangle_Isosceles::__set_edge_C(void)
{
    return (__edges[edges_indexes_t::c]  = sqrt((__edges[edges_indexes_t::a] * __edges[edges_indexes_t::a]) + (__edges[edges_indexes_t::b] * __edges[edges_indexes_t::b])));
}

bool Triangle_Isosceles::is_correct(void) const 
{
    float C = get_angle(angles_indexes_t::C);
    return (Triangle::is_correct() && Triangle_Isosceles::__float_is_equal(C, 90.0));
}
