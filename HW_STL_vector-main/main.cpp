#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
1) Создайте вектор для хранения элементов типа Point.
Сохраните в этом векторе 5 элементов типа Point.
Выведите элементы сохраненного вектора на экран.

2) Создайте ассоциативный массив (контейнер map)
из 5 элементов для сохранения информации о среднем балле студентов.
Каждый элемент этого контейнера будет содержать
пару "имя студента" - средний балл студента.
*/

class Point
{
	int X;
	int Y;
public:
	Point(int x, int y) : X(x),Y(y){}
	friend istream& operator>>(istream& is, Point& P);
	friend ostream& operator<<(ostream& os, const Point& P);
};
istream& operator>>(istream& is, Point& P)
{
	is >> P.X;
	is >> P.Y;
	return is;
}
ostream& operator<<(ostream& os, const Point& P)
{
	os << "X = " << P.X << '\t';
	os << "Y = " << P.Y << '\n';
	return os;
}

int main()
{
    vector<Point> vPoint;
    int x, y;

    for (int i = 0; i < 10; i++)
    {
        x += 1;
        y += 3;
        vPoint.emplace_back(x, y);
    }
    vector<Point>::const_iterator iter;
    short num = 0;
    for (iter = vPoint.begin();iter != vPoint.end(); iter++)
    {
        num+=1;
        cout << " Point #"
        << num << ": "
        << *iter << endl;
    }
    map<string,float>LStudent;
    LStudent.insert(make_pair("Miho1", 4.2));
    LStudent.insert(make_pair("Miho2", 4.2));
    LStudent.insert(make_pair("Miho3", 7.2));
    LStudent.insert(make_pair("Miho4", 4.5));
    LStudent.insert(make_pair("Miho5", 5.2));

    map<string,float>::const_iterator iter_Student;
    for (iter_Student = LStudent.begin();iter_Student != LStudent.end();iter_Student++)
    {
        cout << "Student " << iter_Student->first << " " << iter_Student->second <<  endl;
    }

}