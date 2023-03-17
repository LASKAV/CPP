#include <iostream>
#include <iomanip>

/*
Создайте класс Date, который содержит информацию о дате (день, месяц, год).
С помощью перегрузки операторов определите операцию разности двух дат
(результат - это количество дней между датами), а также операцию увеличения даты
на определенное количество дней
*/

class Data
{
    int day;
    int month;
    int year;
public:
    Data()
    {
        day = NULL;
        month = NULL;
        year = NULL;
    }
    Data(int _data, int _month, int _year)
    {
        day = _data;
        month = _month;
        year = _year;
    }
    Data operator+(const Data& data)  // Перегрузка + 
    {
        return Data(this->day + data.day, this->month + data.month, this->year + data.year);
    }
    Data operator-(const Data& data) // Перегрузка - (разности) 
    {
 
       return Data(this->day - data.day, this->month - data.month, this->year - data.year);
        
    }
    operator int()
    {
        return (this->day, this->month, this->year);
    }
    bool vis(int year)
    {
        return ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0));
    }
    int data(const Data& data_in)
    {
        int days_before_month1 = 30 * data_in.month + (data_in.month + 5) * 4 / 7 - 35 + 2 * (data_in.month < 3);
        int y1 = data_in.year - 1;
        int date1 = data_in.day + days_before_month1 + (vis(data_in.year) && data_in.month > 2) + y1 * 365 + y1 / 4 - y1 / 100 + y1 / 400;
        this->day = date1;
        return date1;
    }
    int data_increm(const Data& data_in)
    {
        int data_num = 0;
        std::cin >> data_num;
        data_in.day + data_num;
        this->day = data_in.day;
        return this->day;
    }
    void print_Data()
    {
        std::cout << "\n" << std::setw(2) << "Date = " << day << "." << month << "." << year << ' ' << std::endl;
    }
    int difference()
    {
        std::cout << "\nhe difference between the dates = " << day << " day" << std::endl;
        return day;
    }
    ~Data()
    {
      
    }
};


int main()
{
    std::cout << "Class DATA! " << std::endl;
    std::cout << "Enter data # 1" << std::endl;
    int day_1 = NULL, month_1 = NULL, year_1 = NULL;
    std::cout << "Enter day : "; std::cin >> day_1;
    std::cout << "Enter month : "; std::cin >> month_1;
    std::cout << "Enter year : "; std::cin >> year_1;
    std::cout << "\nEnter data # 2" << std::endl;
    int day_2 = NULL, month_2 = NULL, year_2 = NULL;
    std::cout << "Enter day : "; std::cin >> day_2;
    std::cout << "Enter month : "; std::cin >> month_2;
    std::cout << "Enter year : "; std::cin >> year_2;
    Data Obj_data1(day_1, month_1, year_1);
    Data Obj_data2(day_2, month_2, year_2);

    Obj_data1.print_Data();
    Obj_data2.print_Data();

    Obj_data1.data(Obj_data1);
    Obj_data2.data(Obj_data2);

    Data data_decrease;
    data_decrease = Obj_data2 - Obj_data1;
    data_decrease.difference();

    Data data_incre;
    data_incre = Obj_data2 + Obj_data1;
    data_incre.difference();
    return 0;
}
