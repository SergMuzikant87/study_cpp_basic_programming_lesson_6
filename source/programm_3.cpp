
#include "triangle.h"
#include "triangle_isosceles.h"
#include "triangle_right_angled.h"
#include "triangle_equilateral.h"
#include "quadrilateral.h"
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "rhomb.h"
#include <iostream>
#include <clocale>

int main(int argc, char * argv [])
{
    setlocale(LC_ALL, "Russian");

    Triangle triangle(10.0, 20.0, 30.0, 50.0, 60.0, 70.0);
    Triangle_Isosceles triangle_isosceles(10.0, 20.0, 50.0, 60.0);
    Triangle_Right_Angled triangle_right_angled(10.0, 20.0, 50.0, 60.0);
    Triangle_Equilateral triangle_equilateral(30.0);
    Quadrilateral quadrilateral(10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0);
    Rectangle rectangle(10.0, 20.0);
    Square square(20.0);
    Parallelogram parallelogram(20.0, 30.0, 30.0);
    Rhomb rhomb(30.0, 30.0);

    triangle.print_info();
    triangle_isosceles.print_info();
    triangle_right_angled.print_info();
    triangle_equilateral.print_info();
    quadrilateral.print_info();
    rectangle.print_info();
    square.print_info();
    parallelogram.print_info();
    rhomb.print_info();
    
    return 0;
}