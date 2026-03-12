
#include "square.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Методы класса "Квадрат"
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////

Square::Square(void) : Rectangle::Rectangle(0.0, 0.0)
{
    __set_name("Квадрат");
}

Square::Square(float a) : Rectangle::Rectangle(a, a)
{
    __set_name("Квадрат");
}

Square::Square(const Square & figure_copyed) : Rectangle(figure_copyed)
{

};

Square & Square::operator= (const Square & figure_copyed)
{
    ::Rectangle::operator= (figure_copyed);
    return *this;
};


bool Square::is_correct(void) const 
{

    for(uint8_t index = edges_indexes_t::a; index <= edges_indexes_t::d; index++)
    {
        if(!Square::__float_is_equal(get_edge(index), get_edge(edges_indexes_t::a)))
        {
            return false;
        }

        if(!Square::__float_is_equal(get_angle(index), 90.0))
        {
            return false;
        }
    }

    return Rectangle::is_correct();
}
