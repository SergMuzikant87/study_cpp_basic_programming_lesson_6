#pragma once

#include <string>
#include <cstdint>
#include <cmath>

////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Символьные обозначения индексов в массивах длин сторон и углов
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum {a, b, c ,d ,e, f, g, h, i, j, k, l, m, n} edges_indexes_t;
typedef enum {A, B, C ,D ,E, F, G, H, I, J, K, L, M, N} angles_indexes_t;

////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Класс "Фигура"
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////

class Figure
{
    private:

    protected:
        std::string __name = "Неизвестная фигура";
        uint8_t __edges_count = 0;
        float * __edges = nullptr;
        float * __angles = nullptr;
        
        void __set_name(std::string name);
        void __set_edge(uint8_t index, float value = 0.0);
        void __set_angle(uint8_t index, float value = 0.0);
        void __set_zero_all(void);

        float __angles_summ_calc(void) const;
        virtual float __get_angles_summ_correct(void) const;
        virtual bool __angles_summ_is_correct(void) const;
        static bool __float_is_equal(float input, float compare, float accuracy = 0.001);
        static float __float_limmit(float input, float minimum = 0.001, float maximum = INFINITY);

    public:
        Figure(void);
        ~Figure(void);
        Figure(std::string name, uint8_t edges_count);
        Figure(const Figure & copy);
        Figure & operator= (const Figure & figure_copyeded); 

        uint8_t get_edges_count(void) const;
        std::string get_name(void) const;
        float get_edge(uint8_t index) const;
        float get_angle(uint8_t index) const;
        
        void print_name(void);
        void print_check_status(void);
        void print_edges_count(void);
        void print_endges_and_angles(void);
        void print_info(void);


        virtual bool is_correct(void) const;
};
