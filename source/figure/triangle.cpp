
#include "triangle.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Методы класса "Треугольник"
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////

Triangle::Triangle(void) : Figure::Figure("Треугольник", 3)
{

}

Triangle::Triangle(float a, float b, float c, float A, float B, float C) : Triangle::Triangle()
{
    __set_edge(edges_indexes_t::a, a);
    __set_edge(edges_indexes_t::b, b);
    __set_edge(edges_indexes_t::c, c);

    __set_angle(angles_indexes_t::A, A);
    __set_angle(angles_indexes_t::B, B);
    __set_angle(angles_indexes_t::C, C);
}

Triangle::Triangle(float a, float b, float c, float A, float B) : Triangle::Triangle(a, b, c, A, B, __float_limmit((180.0 - A - B), 0.001, 179.999))
{

}

Triangle::Triangle(const Triangle & figure_copyed) : Figure(figure_copyed)
{

}

Triangle & Triangle::operator= (const Triangle & figure_copyed)
{
    ::Figure::operator= (figure_copyed);
    return *this;
}

bool Triangle::is_correct(void) const 
{
    return (get_edges_count() == 3) && __angles_summ_is_correct();
}

bool Triangle::__angles_summ_is_correct(void) const
{
    return Triangle::__float_is_equal(__angles_summ_calc(), __get_angles_summ_correct());
}

float Triangle::__get_angles_summ_correct(void) const
{
    return 180.0;
}