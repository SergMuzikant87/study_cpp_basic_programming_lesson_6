
#include "rhomb.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Методы класса "Ромб"
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////

Rhomb::Rhomb(void) :  Parallelogram(0.0, 0.0, 0.0)
{
    __set_name("Ромб");
}

Rhomb::Rhomb(float a, float A) : Parallelogram(a, a, A)
{
    __set_name("Ромб");
}

Rhomb::Rhomb(const Rhomb & figure_copyed) : Parallelogram(figure_copyed)
{

};

Rhomb & Rhomb::operator= (const Rhomb & figure_copyed)
{
    ::Parallelogram::operator= (figure_copyed);
    return *this;
};

bool Rhomb::is_correct(void) const 
{

    for(uint8_t index = 0; index <= 1; index++)
    {
        const uint8_t mask_opposite = 0x02;
        uint8_t index_opposite = index ^ mask_opposite;

        if(!Rhomb::__float_is_equal(get_edge(index), get_edge(edges_indexes_t::a)))
        {
            return false;
        }

        if(!Rhomb::__float_is_equal(get_edge(index_opposite), get_edge(edges_indexes_t::a)))
        {
            return false;
        }

        if(!Rhomb::__float_is_equal(get_angle(index), get_angle(index_opposite)))
        {
            return false;
        }
    }

    return Parallelogram::is_correct();
}