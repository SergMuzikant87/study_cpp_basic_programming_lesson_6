
#include "figure.h"
#include <iostream>


///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Методы базового класса "Фигура"
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////

Figure::Figure(void)
{
    __edges = nullptr;
    __angles = nullptr;
}

Figure::Figure(std::string name, uint8_t edges_count) : Figure::Figure()
{
    __name = name;
    __edges_count = edges_count;
    __edges = new float [__edges_count];
    __angles = new float [__edges_count];
    __set_zero_all();
}

Figure::~Figure(void)
{
    delete [] __edges;
    delete [] __angles;
}

Figure::Figure(const Figure & figure_copyed)
{
    
    if(&figure_copyed == this)
    {
        return;
    };

    __name = figure_copyed.get_name();
    __edges_count = figure_copyed.get_edges_count();
    __edges = new float [__edges_count]{};
    __angles = new float [__edges_count]{};

    for(uint8_t index = 0; index < __edges_count; index++)
    {
        __edges[index] = figure_copyed.get_edge(index);
        __angles[index] = figure_copyed.get_angle(index);
    }
}

Figure & Figure::operator= (const Figure & figure_copyed)
{
    if(&figure_copyed == this) return *this;

    delete [] __edges;
    delete [] __angles;

    __name = figure_copyed.get_name();
    __edges_count = figure_copyed.get_edges_count();
    __edges = new float [__edges_count]{};
    __angles = new float [__edges_count]{};

    for(uint8_t index = 0; index < __edges_count; index++)
    {
        __edges[index] = figure_copyed.get_edge(index);
        __angles[index] = figure_copyed.get_angle(index);
    }

    return *this;
}

uint8_t Figure::get_edges_count(void) const
{
    return __edges_count;
}

void Figure::__set_name(std::string name)
{
    __name = name;
}

void Figure::__set_edge(uint8_t index, float value)
{
    if(index < get_edges_count())
    {
        __edges[index] = Figure::__float_limmit(value);
    }
};

void Figure::__set_angle(uint8_t index, float value)
{
    if(index < get_edges_count())
    {
        __angles[index] = Figure::__float_limmit(value, 0.001, __get_angles_summ_correct());
    }
};

void Figure::__set_zero_all(void)
{
    for(uint8_t index = 0; index < __edges_count; index++)
    {
        __set_edge(index);
        __set_angle(index);
    }
}

float Figure::get_edge(uint8_t index) const
{
    if(index < get_edges_count())
    {
        return __edges[index];
    }
    const float ERROR = -INFINITY;
    return ERROR;
};

float Figure::get_angle(uint8_t index) const
{
    if(index < get_edges_count())
    {
        return __angles[index];
    }
    const float ERROR = -INFINITY;
    return ERROR;
};

std::string Figure::get_name(void) const
{
    return __name;
}

void Figure::print_name(void)
{
    std::cout << get_name() << ":\n";
}

void Figure::print_check_status(void)
{
    std::cout << "инициализирован "<< (is_correct() ? "" : "не ") << "корректно \n";
}

void Figure::print_edges_count(void)
{
    std::cout << "количество сторон: "<< static_cast<unsigned int>(get_edges_count()) << "\n";
}

void Figure::print_endges_and_angles(void)
{
    for(uint8_t property_index = 0; property_index <= 1; property_index++)
    {
        std::cout << (property_index ? "углы: " : "стороны: ");
        float (Figure::*get_property) (uint8_t) const = ((property_index) ? &Figure::get_angle : &Figure::get_edge);
        for(uint8_t elem_index = 0; elem_index < get_edges_count(); elem_index++)
        {
            char property_label = (char)((((uint8_t)'a') & (~(property_index << 5))) + elem_index);
            std::cout << "\'" << property_label << "\' = " <<  (this->*get_property)(elem_index) << ((elem_index >= (get_edges_count() - 1)) ? "" : ", ");     
        };
        std::cout << std::endl; 
    }
    std::cout << std::endl;  
};

void Figure::print_info(void)
{
    //std::cout << "---------------------------------------------------------------------------------------" << std::endl;
    print_name();
    //print_check_status();
    //print_edges_count();
    print_endges_and_angles();
}

bool Figure::is_correct(void) const
{
    return !get_edges_count();
}

float Figure::__angles_summ_calc(void) const
{
    float angles_summ = 0.0;
    for(uint8_t index = 0; index < __edges_count; index++)
    {
        angles_summ += get_angle(index);
    }
    return angles_summ;
}

float Figure::__get_angles_summ_correct(void) const
{
    return 360.0;
}

bool Figure::__angles_summ_is_correct(void) const
{
    return true;
}

bool Figure::__float_is_equal(float input, float compare, float accuracy)
{
    return (input >= (compare - accuracy)) && (input <= (compare + accuracy));
}

float Figure::__float_limmit(float input, float minimum, float maximum)
{
    return (input < minimum) ? minimum : (input > maximum) ? maximum : input;
}