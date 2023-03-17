#include <iostream>
#include "Complex.h"

/*
Реализовать класс "Комплексное число". 
Наполните класс перегруженными операторами + и * для сложения и умножения комплексных чисел.
Перегрузите оператор << для вывода на экран комплексного числа

*/

void frame();

int main()
{
	float A1 = NULL ,A2 = NULL;
	float B1 = NULL ,B2 = NULL;
	frame();
	std::cout << "Enter real part (1): ";
	std::cin >> A1;
	std::cout << "Enter real part (2): ";
	std::cin >> A2;
	std::cout << "Enter imaginary part (1): ";
	std::cin >> B1;
	std::cout << "Enter imaginary part (2): ";
	std::cin >> B2;
	frame();
	std::cout << " z1 = " << A1 << " + " << B1 << "i" << std::endl;
	std::cout << " z2 = " << A2 << " + " << B2 << "i" << std::endl;
	Complex Z1_complex(A1, B1);
	Complex Z2_complex(A2, B2);
	frame();
	std::cout << "Complex (+)" << std::endl;
	std::cout << "z1 + z2" << std::endl;
	Complex Addition_z1_z2 = Z1_complex + Z2_complex;
	std::cout << Addition_z1_z2;
	frame();
	std::cout << "Complex (*)" << std::endl;
	std::cout << "z1 * z2" << std::endl;
	Complex Multiply_z1_z2 = Z1_complex * Z2_complex;
	std::cout << Multiply_z1_z2;
	frame();
    return 0;
}

void frame()
{
	for (int i = 0; i < 35; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}
