#include "parallelogram.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Методы класса "Параллелограмм"
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////

Parallelogram::Parallelogram(void) : Quadrilateral::Quadrilateral()
{
    __set_name("Параллелограмм");
    __set_edges_all(edges_indexes_t::a, 0.0, 0.0);
    __set_angles_all(angles_indexes_t::A, 0.0);
}

Parallelogram::Parallelogram(float a, float b, float A)
{
    __set_name("Параллелограмм");
    __set_edges_all(edges_indexes_t::a, a, b);
    __set_angles_all(angles_indexes_t::A, A);
}

Parallelogram::Parallelogram(const Parallelogram & figure_copyed) : Quadrilateral(figure_copyed)
{

};

Parallelogram & Parallelogram::operator= (const Parallelogram & figure_copyed)
{
    ::Quadrilateral::operator= (figure_copyed);
    return *this;
};

void Parallelogram::__set_angles_all(uint8_t index, float angle)
{
    const uint8_t indexes_mask = 0x03;
    const uint8_t indexes_adjacent_mask = 0x01;
    const uint8_t indexes_opposite_mask = 0x02;

    index = index & indexes_mask;
    __set_angle(index, angle);
    
    float angle_adjacent = 180.0 - get_angle(index);
    
    __set_angle((index ^ indexes_opposite_mask), angle);
    __set_angle((index ^ indexes_adjacent_mask), angle_adjacent);
    __set_angle((index ^ (indexes_adjacent_mask | indexes_opposite_mask)), angle_adjacent);
}

void Parallelogram::__set_edges_opposite(uint8_t index, float edge)
{
    uint8_t indexes_mask = 0x03;
    index = index & indexes_mask;
    __set_edge(index, edge);
    __set_edge((index ^ 0x02), edge);
}

void Parallelogram::__set_edges_all(uint8_t edge_index, float edge, float edge_adjacent)
{
    uint8_t indexes_mask = 0x03;
    edge_index = edge_index & indexes_mask;
    __set_edges_opposite(edge_index, edge);
    __set_edges_opposite((edge_index ^ 0x01), edge_adjacent);
}

bool Parallelogram::is_correct(void) const 
{
    for(uint8_t index = 0; index <= 1; index++)
    {
        const uint8_t mask_opposite = 0x02;
        uint8_t index_opposite = index ^ mask_opposite;

        if(!Parallelogram::__float_is_equal(get_edge(index), get_edge(index_opposite)))
        {
            return false;
        }

        if(!Parallelogram::__float_is_equal(get_angle(index), get_angle(index_opposite)))
        {
            return false;
        }
    }

    return Quadrilateral::is_correct();
}
