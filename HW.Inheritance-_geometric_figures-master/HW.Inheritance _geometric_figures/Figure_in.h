#include <iostream>

using namespace std;

/*
2) Используя множественное наследование, разработать класс “Окружность, вписанная в квадрат”.
*/

/*
Площадь круга вписанного в квадрат меньше площади квадрата в 4/π раза.
*/

class Circumference
{
protected:
	int side;
public:
	Circumference()
	{
		side = 8;
	}
	void show_Circumference()
	{
		cout
			<< "___CIRCUMFERENCE___" << endl
			<< " Side = " << side << endl;
	}
};

class Quad
{
protected:
	int area;
public:
	Quad()
	{
		area = 32;
	}
	void show_Quad()
	{
		cout
			<< "___QUAD___" << endl
			<< " Area = " << area << endl;
	}
};

class Circumference_and_Quad : public Circumference, public Quad
{
public:
	void show_Circumference_and_Quad()
	{
		if ((Circumference::side / 4) < Quad::area)
		{
			cout << " Good , square in circle ! " << endl;
		}
		else
		{
			cout << " No , square in circle ! " << endl;
		}
	}
};
