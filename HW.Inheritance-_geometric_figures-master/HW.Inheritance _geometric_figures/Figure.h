#include <iostream>

using namespace std;

/*
1) Используя наследование, создайте классы для геометрических фигур (см. рисунок из презентации по наследованию).
Базовый класс будет содержать одно поле - сторона фигуры.
*/

class Figure  
{
protected:
	short side;
public:
	Figure()
	{
		side = 5;
	}
	void show_Figure()
	{
		cout
			<< "___FIGURE___" << endl
			<< " Side = " << side << endl;
	}
};
class Triangle : public Figure
{
public:
	Triangle() : Figure()
	{
		side = 6;
	}
	void show_Triangle()
	{
		Figure::show_Figure();

		double Area = pow(side, 2) * sqrt(3) / 4;
		double Perimeter = side * 3;

		cout
			<< "___TRIANGLE___" << endl
			<< " Perimeter = " << Perimeter << endl
			<< " Area = " << Area << endl;
	}
};
class Square : public Figure
{
public:
	Square() : Figure()
	{
		side = 8;
	}
	void show_Squaer()
	{
		Figure::show_Figure();

		double Area = pow(side, 2);
		double Perimeter = side * 4;

		cout
			<< "___SQUAER___" << endl
			<< " Perimeter = " << Perimeter << endl
			<< " Area = " << Area << endl;

	}
};
class Rectangle : public Figure
{
public:
	Rectangle() : Figure()
	{
		side = 4;
	}
	void show_Rectangle()
	{
		Figure::show_Figure();

		double Area = side * side;             // S = a x b 
		double Perimeter = 2 * (side * side);  // P = 2 x (a + b)

		cout
			<< "___RECTANGLE___" << endl
			<< " Perimeter = " << Perimeter << endl
			<< " Area = " << Area << endl;
	}
};
class Circle : public Figure
{
public:
	Circle()
	{
		side = 8;
	}
	void show_Circle()
	{
		Figure::show_Figure();

		double Area = 3.14 * pow(side, 2);         // S = 3.14 * r2
		double Perimeter = 2 * 3.14 * side;         // C = 2 * 3.14 * side 

		cout
			<< "___CIRCLE___" << endl
			<< " Perimeter = " << Perimeter << endl
			<< " Area = " << Area << endl;

	}

};
