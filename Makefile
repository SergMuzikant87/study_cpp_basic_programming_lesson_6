CC := g++
FLAGS := -Wall -O2 -std=c++11 -Isource/figure

build:
	$(CC) $(FLAGS) -c source/mathematic.cpp -o output/mathematic.o
	$(CC) $(FLAGS) -c source/programm_1.cpp -o output/programm_1.o

	$(CC) $(FLAGS) -c source/programm_2.cpp -o output/programm_2.o
	$(CC) $(FLAGS) -c source/comand.cpp -o output/comand.o
	$(CC) $(FLAGS) -c source/counter.cpp -o output/counter.o

	$(CC) $(FLAGS) -c source/programm_3.cpp -o output/programm_3.o
	$(CC) $(FLAGS) -c source/figure/figure.cpp -o output/figure.o
	$(CC) $(FLAGS) -c source/figure/triangle.cpp -o output/triangle.o
	$(CC) $(FLAGS) -c source/figure/triangle_isosceles.cpp -o output/triangle_isosceles.o
	$(CC) $(FLAGS) -c source/figure/triangle_right_angled.cpp -o output/triangle_right_angled.o
	$(CC) $(FLAGS) -c source/figure/triangle_equilateral.cpp -o output/triangle_equilateral.o
	$(CC) $(FLAGS) -c source/figure/quadrilateral.cpp -o output/quadrilateral.o
	$(CC) $(FLAGS) -c source/figure/rectangle.cpp -o output/rectangle.o
	$(CC) $(FLAGS) -c source/figure/square.cpp -o output/square.o
	$(CC) $(FLAGS) -c source/figure/parallelogram.cpp -o output/parallelogram.o
	$(CC) $(FLAGS) -c source/figure/rhomb.cpp -o output/rhomb.o
	
	$(CC) $(FLAGS)  output/mathematic.o output/programm_1.o  -o output/programm_1
	$(CC) $(FLAGS)  output/counter.o output/comand.o output/programm_2.o  -o output/programm_2
	$(CC) $(FLAGS)  output/figure.o output/triangle.o output/triangle_isosceles.o output/triangle_right_angled.o output/triangle_equilateral.o output/quadrilateral.o output/rectangle.o output/square.o output/parallelogram.o output/rhomb.o output/programm_3.o  -o output/programm_3
