#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "colors.h"  // цвета 
#include <string>
#include <fstream>   // работа с файлами >> 



void uppercase_print()  // шапка 
{
	std::cout << colors::BLACK_BOLD << "___________________________________________________ Terminal ___________________________________________________________" << colors::RESET << std::endl;
}
void Specify_file_path()  // пример ввода 
{
	std::cout << colors::GREEN_BOLD << "\nУказать путь к файлу " << colors::RESET
		<< "\n" << colors::WHITE_BOLD << "Пример : C:\\Users\\CPU\\Documents\\file_target.txt" << colors::RESET << std::endl;
	std::cout << colors::WHITE_BOLD << "Введите путь : " << colors::RESET;

}
void file_rezalt(std::string rezalt)  //  вывод данных полученных от пользователя 
{
	std::cout << colors::GREEN_BOLD << " >> " << colors::RESET << colors::WHITE_BOLD << std::string(rezalt) << colors::RESET
		<< colors::GREEN_BOLD << " << " << colors::RESET << std::endl;

}
void error_open_file(std::string rezalt_open)  // вывод ошибки 
{
	std::cout << colors::RED_BOLD << "\nОшибка : открытия файла " << std::string(rezalt_open) << colors::RESET << std::endl;
	std::cout << colors::RED_BOLD << "Нужно корректно указать путь к файлу" << colors::RESET << std::endl;
	std::cout << colors::GREEN_BOLD << "\n1. Указать путь к файлу " << colors::RESET << std::endl;
	std::cout << colors::GREEN_BOLD << "\n2. Выйти" << colors::RESET << std::endl;
	std::cout << colors::WHITE_BOLD << "\nВыберите цифру : " << colors::RESET;
}
void job_completion(std::string name_file)  // завершение работы          явное преобразование 
{                                                                               // |
	std::cout << colors::RED_BOLD << "\nОшибка : открытия файла " << std::string(name_file) << colors::RESET << std::endl;
	std::cout << colors::RED_BOLD << "Нужно корректно указать путь к файлу" << colors::RESET << std::endl;
	std::cout << colors::BLACK_BOLD << "\nTerminal : " << colors::RESET
		<< colors::GREEN_BOLD << "Завершение работы " << colors::RESET << std::endl;
}
void main_menu()
{
	std::cout << colors::BLACK_BOLD << "\nTerminal : " << colors::RESET
		<< colors::GREEN_BOLD << "Menu " << colors::RESET << std::endl << std::endl;
	std::cout << colors::GREEN_BOLD
		<< "1. Выбрать файл" << std::endl
		<< "2. Показать содержимое файла" << std::endl
		<< "3. Статистика" << std::endl
		<< "4. Очистить консоль" << std::endl
		<< "5. Выйти " << colors::RESET << std::endl;
	std::cout << colors::WHITE_BOLD << "\nВыберите цифру : " << colors::RESET;
}
void file_open(std::string name_file)
{
	std::cout << colors::BLACK_BOLD << "\nTerminal : " << colors::RESET
		<< colors::GREEN_BOLD << "Открыт " << std::string(name_file) << colors::RESET << std::endl << std::endl;
}

void file_cloes(std::string name_file)
{
	std::cout << colors::BLACK_BOLD << "\nTerminal : " << colors::RESET
		<< colors::GREEN_BOLD << "Конец файла " << std::string(name_file) << colors::RESET << std::endl;
}

void exit_file_closed(std::string name_file)
{
	std::cout << colors::BLACK_BOLD << "\nTerminal : " << colors::RESET
		<< colors::GREEN_BOLD << "Завершение работы " << colors::RESET << std::endl;
	std::cout << colors::BLACK_BOLD << "\nTerminal : " << colors::RESET
		<< colors::GREEN_BOLD << "Файл закрыт " << std::string(name_file) << colors::RESET << std::endl;
}

int num_str(char* num_s)  // Количество символов
{
	std::cout << colors::GREEN_BOLD << "Количество символов = " << colors::RESET << colors::RED_BOLD << strlen(num_s) << colors::RESET << std::endl;
	int rezalt = strlen(num_s);
	return rezalt;
}

int num_vowels_and_consonants(char* num_s)  // Количество гласных и согласных
{
	int rezalt = strlen(num_s);
	int iter1 = 0;
	int iter2 = 0;
	for (size_t i = 0; i < rezalt; i++)
	{
		if (num_s[i] == 'a' || num_s[i] == 'e' || num_s[i] == 'i' ||
			num_s[i] == 'o' || num_s[i] == 'u' || num_s[i] == 'y')
		{
			iter1++;
		}
		else
		{
			iter2++;
		}
	}
	std::cout << colors::GREEN_BOLD << "Количество гласных = " << colors::RESET << colors::RED_BOLD << iter1 << colors::RESET << std::endl;
	std::cout << colors::GREEN_BOLD << "Количество согласных = " << colors::RESET << colors::RED_BOLD << iter2 << colors::RESET << std::endl;
	return iter1, '\n', iter2;
}



int num_num(char* num_s)  //  Количество цифр.
{
	int rezalt = strlen(num_s);
	int iter = 0;
	for (size_t i = 0; i < rezalt; i++)
	{
		if (num_s[i] == '0' || num_s[i] == '1' || num_s[i] == '2' ||
			num_s[i] == '3' || num_s[i] == '4' || num_s[i] == '5' ||
			num_s[i] == '6' || num_s[i] == '7' || num_s[i] == '8' ||
			num_s[i] == '9')
		{
			iter++;
		}

	}
	std::cout << colors::GREEN_BOLD << "Количество цифр = " << colors::RESET << colors::RED_BOLD << iter << colors::RESET << std::endl;
	return iter;
}

int main()
{
	setlocale(LC_ALL, "ru");    //  Подключаем язык 
	std::string name_file;      //  Хранит в себе имя файла
	std::string str;            //  Для вывода данных из файла 
	uppercase_print();
	short batton_num = 0;       //  Для выбора доп.меню 
	bool flag = false;          //  Остановка цикла 

	do
	{
		std::ifstream File_target;  // создаем объект класса ifstream
		main_menu();
		std::cin >> batton_num;
		File_target.open(name_file);  // открываем файл

		if (batton_num == 1 || batton_num == 2
			|| batton_num == 3 || batton_num == 4 || batton_num == 5)  // Делаем проверку для корректной работы  
		{
			if (batton_num == 1)  // "1. Выбрать файл"
			{
				Specify_file_path();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // cin >> , нужно сбрасывать буфер, и получать новые данные от пользователя.
				std::getline(std::cin, name_file);  // cчитываем всю строку , + пробелы если это не делать то адреса к файлу не будет 
				file_rezalt(name_file);
				File_target.open(name_file);
				if (!File_target.is_open())  // Проверка на открытие файла 
				{
					error_open_file(name_file);  // Выводим ошибку и попадыем в доп.меню 
					short num_menu = 0;
					std::cin >> num_menu;
					if (num_menu == 1 || num_menu == 2)
					{
						if (num_menu == 1)
						{
							Specify_file_path();
							std::cout << colors::BLACK_BOLD << "\nTerminal : " << colors::RESET;
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::getline(std::cin, name_file);
							file_rezalt(name_file);
							File_target.open(name_file);  // при вводе навых данных нужно открывать файл 
							if (!File_target.is_open())   // Если файл не удалось открыть опять , останавливаем программу 
							{
								std::cout << colors::RED_BOLD << "\nОшибка : открытия файла " << std::string(name_file) << colors::RESET << std::endl;
								std::cout << colors::RED_BOLD << "Нужно корректно указать путь к файлу" << colors::RESET << std::endl;
								std::cout << colors::BLACK_BOLD << "\nTerminal : " << colors::RESET;
								flag = true;      // конец цикла 
							}
							File_target.close();
						}
						if (num_menu == 2)  // выход 
						{
							job_completion(name_file);
							system("pause");  // делаем паузу 
							return -1;        // стоп 
						}
					}
					else
					{
						std::cout << colors::BLACK_BOLD << "Terminal : " << colors::RESET << colors::RED_BOLD << "ERROR" << colors::RESET
							<< colors::RED_BOLD << "\nНужно ввести число которое соответстувет выбору в menu !" << colors::RESET << std::endl;
						flag = true;
					}
				}
			}
			if (batton_num == 2)  // "2. Показать содержимое файла"
			{
				std::ifstream File_target;
				File_target.open(name_file);
				file_open(name_file);
				int iter = 0;    // счетчик , для количество строк 
				// Теперь для статистики нам надо спарсить данные которые мы открыли, они будут хранится в файле "data.txt" если у вас его нет 
				// программа сама его создаст. Данные в  data.txt будут храниться не как оригинал , они будут в 1 строку и 1 столбец , для удобного 
				// подсчета статистики , и каждый раз они будут перезаписаны как только пользователь захочет посмотреть что хранит в себе файл. 
				std::ofstream file;  
				file.open("data.txt");
				if (file.is_open() && File_target.is_open())
				{
					while (!File_target.eof())  // цикл будет рабоать пока не дайдет до конца файла
					{
						str = "";
						std::getline(File_target, str);
						std::cout << str << std::endl;  // выводим содержимое файла 
						file << str;  // и потоком передаем данные в data.txt
						iter++;
					}
					file_cloes(name_file);

					//if (file.is_open())  // Если файл удалось прочесть выводим сколько строк он имеет 

					std::cout << colors::BLACK_BOLD << "\nTerminal  " << colors::RESET
						<< colors::GREEN_BOLD << "Количество строк = " << colors::RESET << iter << std::endl;
				}				
			}
			if (batton_num == 3)
			{
				const unsigned int BUFF = 1000000;  // создаем буфер на 1м 

				FILE* File_scan = fopen("data.txt", "rt");  // "rt" - для чтения в текстовом виде с начала файла
				// Теперь мы будем сканировать и для этого я выбрал вариант С 
				if (File_scan == NULL)
				{
					job_completion(name_file);
					return -1;
				}
				char file_txt[BUFF];     // обявляем массив char
				fgets(file_txt, BUFF, File_scan);  // передаем все в массив 

				std::cout << colors::WHITE_BOLD << "___Statistics___" << colors::RESET << std::endl;  // выводим статистику 
				num_str(file_txt);
				num_vowels_and_consonants(file_txt);
				num_num(file_txt);
			}
			if (batton_num == 4)  // "4. Очистить консоль"
			{
				system("cls");    // чистим консть 
			}
			if (batton_num == 5)  // "5. Выход"
			{
				FILE* File_scan = fopen("data.txt", "rt");
				std::ifstream File_target;
				std::ofstream file;
				exit_file_closed(name_file);
				file.close();         	   // 
				fclose(File_scan);		   //  Закрываем наши файлы 
				File_target.close();	   // 
			}
		} else
			{
				std::cout << colors::BLACK_BOLD << "Terminal : " << colors::RESET << colors::RED_BOLD << "ERROR" << colors::RESET
					<< colors::RED_BOLD << "\nНужно ввести число которое соответстувет выбору в menu !" << colors::RESET << std::endl;
				flag = true;
			}
	}while (batton_num != 5 && flag == false);  // Условия выхода

		system("pause");

		return 0;
}