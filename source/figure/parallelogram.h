#pragma once

#include "quadrilateral.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Класс "Параллелограмм"
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Parallelogram : public Quadrilateral
{
    private:
        void __set_angles_all(uint8_t index, float angle);
        void __set_edges_all(uint8_t edge_index, float edge, float edge_adjacent);
        void __set_edges_opposite(uint8_t index, float edge);

    public:
        Parallelogram(void);
        Parallelogram(float a, float b, float A);
        Parallelogram(const Parallelogram & figure_copyed);
        Parallelogram & operator= (const Parallelogram & figure_copyed);

        bool is_correct(void) const override;
};