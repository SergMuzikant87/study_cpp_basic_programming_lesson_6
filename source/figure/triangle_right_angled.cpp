#include "triangle_right_angled.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Методы класса "Равнобедренный треугольник"
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

Triangle_Right_Angled::Triangle_Right_Angled(void) : Triangle::Triangle()
{
    __set_name("Равнобедренный треугольник");
}

Triangle_Right_Angled::Triangle_Right_Angled(float a, float b, float A, float B) : Triangle::Triangle(a, b, a, A, B, A) 
{
    __set_name("Равнобедренный треугольник");
}

Triangle_Right_Angled::Triangle_Right_Angled(const Triangle_Right_Angled & figure_copyed) : Triangle(figure_copyed)
{

};

Triangle_Right_Angled & Triangle_Right_Angled::operator= (const Triangle_Right_Angled & figure_copyed)
{
    ::Triangle::operator= (figure_copyed);
    return *this;
};

bool Triangle_Right_Angled::is_correct(void) const 
{
    return Triangle::is_correct() && (get_edge(edges_indexes_t::a) == get_edge(edges_indexes_t::c)) && (get_angle(angles_indexes_t::A) == get_angle(angles_indexes_t::C));
}