#include <iostream>

using namespace std;

/*
Написать функцию, определяющую, является ли счастливым 6-значное число.
Функция должна выбрасывать два исключения.
Первое исключение - если число содержит 5 или менее цифр.
Второе исключение - если число содержит 7 или более цифр.
Второе исключение выбросите с использованием класса exception.
Исключения обрабатываем в main()
*/

void happy_num(int num)
{

	cout << "num \% 10 = " << num % 10 << endl;
	cout << "(num \% 100) / 10 = " << (num % 100) / 10 << endl;
	cout << "(num \% 1000) / 100 = " << (num % 1000) / 100 << endl;

	cout << "num / 100000 = " << num / 100000 << endl;
	cout << "(num / 10000) \% 10 " << (num / 10000) % 10 << endl;
	cout << "(num / 1000) \% 10 = " << (num / 1000) % 10 << endl;

	if (num > 100000 && num < 999999)
	{
		if (((num % 10) + (num % 100) / 10 + (num % 1000) / 100) == ((num / 100000) + (num / 10000) % 10 + (num / 1000) % 10))
		{
			cout << "happy" << endl;
		}
		else
		{
			cout << "No happy" << endl;
		}
	}
	else
	{
		if (num < 99999 && num > 10000)
		{
			throw "The first exception is if the number contains 5 or less digits.";
		}
		else if (num > 1000000 && num < 99999999)
		{
			throw exception("The second exception is if the number contains 7 or more digits.");
		}
	}
	
}


int main()
{
	int num = 333621;

	try
	{
		happy_num(num);
	}
	catch (const char* str)
	{
		cout << "\nError # 1 :" << str << endl;
	}
	catch (const exception& str)
	{
		cout << "\nError # 2 : " << str.what() << endl;
	}
	return 0;
}
