// Даются два текстовых файла.Узнайте, совпадают ли их строки .Если нет, 
// то отобразите строку, которая не совпадает из каждого файла.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>


void viz();

int main()
{
	setlocale(LC_ALL, "ru");

	// "file1.txt"
	// "file2.txt"
		 
	FILE* F = fopen("file1.txt", "rt");  // "rt" - для чтения в текстовом виде с начала файла

	if (F == NULL)
	{
		std::cout << "File 1 не обнаружен" << std::endl;
		return -1;
	}
	std::cout << "File 1 открыт  " << std::endl;


	char str1[100];
	fgets(str1, 100, F);

	viz();
	std::cout << str1;
	viz();

	FILE* G = fopen("file2.txt", "rt");  // "rt" - для чтения в текстовом виде с начала файла

	if (G == NULL)
	{
		std::cout << "File 2 не обнаружен" << std::endl;
		return -1;
	}
	std::cout << "File 2 открыт " << std::endl;

	char str2[100];
	fgets(str2, 100, G);

	viz();
	std::cout << str2;
	viz();

	std::cout << "file1.txt = " << strlen(str1) << std::endl; // Длина строки file1.txt
	std::cout << "file2.txt = " << strlen(str2) << std::endl; // Длина строки file2.txt
	int rezalt1 = strlen(str1);
	int rezalt2 = strlen(str2);
	

	if (rezalt1 == rezalt2) // Делаем проверку сопадают строки или нет ?
	{
		std::cout << "Строки совпадают! " << std::endl;

	}
	else
	{
		std::cout << "Cтроки не совпадают" << std::endl;
		
		for (size_t i = 0; i < rezalt2; i++) // Берем от длина строки file2.txt
		{

			if (str2[i] == str1[i])
			{
				
			}
			else
			{
				std::cout << str2[i];
			}				
		}
	}
	
	fclose(F);
	fclose(G);

	return 0;
}

void viz()
{
	std::cout << std::endl;
	for (size_t i = 0; i < 60; i++)
	{
		std::cout << char(126);
	}
	std::cout << std::endl;
}

