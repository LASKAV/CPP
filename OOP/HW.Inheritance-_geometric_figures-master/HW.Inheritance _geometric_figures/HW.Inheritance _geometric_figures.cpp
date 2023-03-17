#include <iostream>
#include "Figure.h"
#include "Figure_in.h"
using namespace std;

/*
1) Используя наследование, создайте классы для геометрических фигур (см. рисунок из презентации по наследованию).
Базовый класс будет содержать одно поле - сторона фигуры.

2) Используя множественное наследование, разработать класс “Окружность, вписанная в квадрат”.
*/
 

int main()
{
	Triangle Obj_Tri;
	Obj_Tri.show_Triangle();

	Square Obj_Squ;
	Obj_Squ.show_Squaer();
	
	Rectangle Obj_Rect;
	Obj_Rect.show_Rectangle();

	Circle Obj_Cire;
	Obj_Cire.show_Circle();

	Circumference_and_Quad Obj_cir_qua;
	Obj_cir_qua.show_Circumference_and_Quad();

	return 0;
}
