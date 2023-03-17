#include <iostream>
using namespace std;

/*
Создайте класс Passport (паспорт), который будет содержать паспортную информацию о гражданине Украины.
С помощью механизма наследования реализуйте класс ForeignPassport (загранпаспорт), производный от Passport.
Напомним, что загранпаспорт содержит помимо паспортных данных, также данные о визах, номер загранпаспорта
*/
class Passport
{
protected:
	int Document;
	string Nationality;
	string Surname;
	string Name;
	string Patronymic;
	string Sex;
	string Data_of_brth;
	string Data_of_expiry;
public:
	Passport()
	{
		Document = 54645734;
	    Nationality = "UKR";
	    Surname = "IVAN";
	    Name = "IVAN";
	    Patronymic = "IVANOV";
	    Sex = "M";
	    Data_of_brth = "11.11.1999";
	    Data_of_expiry = "12.12.2030";
	}
	void Set_Document_num()
	{
		cout << "Enter num document ID : "; cin >> Document;
	}
	void Set_FIO()
	{
		cout << "Enter Surname : "; cin >> Nationality;
		cout << "Enter Name: "; cin >> Name;
		cout << "Patronymic :"; cin >> Patronymic;
	}
	void Set_Data()
	{
		cout << "Enter Sex (M/F) : "; cin >> Sex;
		cout << "Enter Data_of_brth : "; cin >> Data_of_brth;
		cout << "Enter Data_of_expiry : "; cin >> Data_of_expiry;
	}
	void Print_()
	{
		cout
			<< "___Passport___" << endl
			<< "Document ID : " << Document << endl
			<< "Nationality : " << Nationality << endl
			<< "Surname : " << Surname << endl
			<< "Name : " << Name << endl
			<< "Patronymic : " << Patronymic << endl
			<< "Sex : " << Sex << endl
			<< "Data_of_brth : " << Data_of_brth << endl
			<< "Data_of_expiry " << Data_of_expiry << endl;
	}
	~Passport()
	{

	}
};

class ForeignPassport : public Passport
{
	string VIZA;
	int ForeignDocument;

public:

	ForeignPassport()
	{
		VIZA = "xxxxxx";
		ForeignDocument = 305323623;
		Document = 54645734;
		Nationality = "UKR";
		Surname = "IVAN";
		Name = "IVAN";
		Patronymic = "IVANOV";
		Sex = "M";
		Data_of_brth = "11.11.1999";
		Data_of_expiry = "12.12.2030";
	}
	void Print_()
	{
		cout 
			<< "___ForeignPassport___" << endl
			<< "VIZA : " << VIZA << endl 
		    << "ForeignDocument : " << ForeignDocument << endl
			<< "Document ID : " << Document << endl
			<< "Nationality : " << Nationality << endl
			<< "Surname : " << Surname << endl
			<< "Name : " << Name << endl
			<< "Patronymic : " << Patronymic << endl
			<< "Sex : " << Sex << endl
			<< "Data_of_brth : " << Data_of_brth << endl
			<< "Data_of_expiry " << Data_of_expiry << endl;
	}
};

int main()
{
	Passport ID_one;
	ID_one.Print_();

	ForeignPassport Foreign_one;
	Foreign_one.Print_();

	return 0;
}

