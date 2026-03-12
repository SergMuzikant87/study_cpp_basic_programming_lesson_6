#include "quadrilateral.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Методы класса "Четырёхугольник"
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

Quadrilateral::Quadrilateral(void) : Figure("Четырёхугольник", 4) 
{
};

Quadrilateral::Quadrilateral(float a, float b, float c, float d, float A, float B, float C, float D) : Quadrilateral::Quadrilateral()
{
    __set_edge(edges_indexes_t::a, a);
    __set_edge(edges_indexes_t::b, b);
    __set_edge(edges_indexes_t::c, c);
    __set_edge(edges_indexes_t::d, d);

    __set_angle(angles_indexes_t::A, A);
    __set_angle(angles_indexes_t::B, B);
    __set_angle(angles_indexes_t::C, C);
    __set_angle(angles_indexes_t::D, D);

};

Quadrilateral::Quadrilateral(float a, float b, float c, float d, float A, float B, float C) : Quadrilateral::Quadrilateral(a, b, c, d, A, B, C, __float_limmit((360.0 - A - B - C), 0.001, 359.999))
{

};

Quadrilateral::Quadrilateral(const Quadrilateral & figure_copyed) : Figure(figure_copyed)
{

};

Quadrilateral & Quadrilateral::operator= (const Quadrilateral & figure_copyed)
{
    ::Figure::operator= (figure_copyed);
    return *this;
};

bool Quadrilateral::is_correct(void) const 
{
    return (get_edges_count() == 4) && __angles_summ_is_correct();;
}

bool Quadrilateral::__angles_summ_is_correct(void) const
{
    return Quadrilateral::__float_is_equal(__angles_summ_calc(), __get_angles_summ_correct());
}

float Quadrilateral::__get_angles_summ_correct(void) const
{
    return 360.0;
}
