
#include "rectangle.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Методы класса "Прямоугольник"
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////

Rectangle::Rectangle(void) : Parallelogram::Parallelogram(0.0, 0.0, 90.0)
{
    __set_name("Прямоугольник");
}

Rectangle::Rectangle(float a, float b) : Parallelogram::Parallelogram(a, b, 90.0)
{
    __set_name("Прямоугольник");
}

Rectangle::Rectangle(const Rectangle & figure_copyed) : Parallelogram(figure_copyed)
{

};

Rectangle & Rectangle::operator= (const Rectangle & figure_copyed)
{
    ::Parallelogram::operator= (figure_copyed);
    return *this;
};

bool Rectangle::is_correct(void) const 
{
    for(uint8_t index = 0; index <= 1; index++)
    {
        const uint8_t mask_opposite = 0x02;
        uint8_t index_opposite = index ^ mask_opposite;

        if(!Rectangle::__float_is_equal(get_edge(index), get_edge(index_opposite)))
        {
            return false;
        }

        if(!Rectangle::__float_is_equal(get_angle(index), 90.0))
        {
            return false;
        }

        if(!Rectangle::__float_is_equal(get_angle(index_opposite), 90.0))
        {
            return false;
        }
    }

    return Parallelogram::is_correct();
}
