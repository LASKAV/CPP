#include <iostream>
#include "DynArray.h"

/*
Создать шаблонный класс динамического массива (см. урок №2, с. 56).
Добавить в этот класс методы для добавления элемента к массиву и удаления элемента из массива
2) В ранее созданный шаблонный класс динамического массива (см. предыдущие ДЗ)
добавить метод для расчета суммы элементов этого массива. Создать объекты этого класса, 
инкаспулирующие массивы типа int, double, char и Point.
Point - это класс, содержащий 2 поля (координаты точки): int x и int y.

*/

int main()
{
	DynArray <int> arry_one{ 5 };
	arry_one.randomize();
	arry_one.print();
	arry_one.AddElement(5);
	arry_one.print();
	arry_one.DellElement(2);
	arry_one.print();
	arry_one.SumElement();

	DynArray <char> arry_char{ 5 };
	arry_char.randomize();
	arry_char.print();
	arry_char.AddElement(2);
	arry_char.print();
	arry_char.DellElement(1);
	arry_char.print();
	arry_char.SumElement();

	DynArray <double> arry_double{ 5 };
	arry_double.randomize();
	arry_double.print();
	arry_double.AddElement(1);
	arry_double.print();
	arry_double.DellElement(1);
	arry_double.print();
	arry_double.SumElement();

	DynArray <Point> arry_Point{ 10 };
	arry_Point.randomize();
	arry_Point.print();
	arry_Point.SumElement();

	return 0;
}
