#include "mathematic.h"
#include <iostream>
#include <clocale>

enum operation_t
{
    SUMM = 1,
    DIFF,
    MULT,
    DIV,
    POW
};

int main(int argc, char * argv [])
{
    setlocale(LC_ALL, "Russian");
    
    int32_t value_1{};
    int32_t value_2{};
    uint16_t operation{};

    std::cout << "Введите число 1: "; std::cin >> value_1; 
    std::cout << "Введите число 2: "; std::cin >> value_2; 
    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): "; std::cin >> operation;

    switch(operation)
    {
        case SUMM: std::cout << value_1 << " + " << value_2 << " = " << summ_int32(value_1, value_2) << std::endl; break;
        case DIFF: std::cout << value_1 << " - " << value_2 << " = " << diff_int32(value_1, value_2) << std::endl; break;
        case MULT: std::cout << value_1 << " * " << value_2 << " = " << mult_int32(value_1, value_2) << std::endl; break;
        case DIV: std::cout << value_1 << " / " << value_2 << " = " << div_int32(value_1, value_2) << std::endl; break;
        case POW: std::cout << value_1 << " в степени " << value_2 << " = " << pow_uint32(value_1, value_2) << std::endl; break;
        default: std::cout << " Введена некорректная команда. " << std::endl; 
    }

    return 0;
}