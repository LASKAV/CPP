#include <iostream>

// 2) В ранее созданный шаблонный класс динамического массива(см.предыдущие ДЗ)
// добавить метод для расчета суммы элементов этого массива.
// Создать объекты этого класса, инкаспулирующие массивы типа int, double, char и Point.
// Point - это класс, содержащий 2 поля(координаты точки) : int x и int y.

class Point
{
	int x;
	int y;
public:

	Point()
	{
		x = NULL;
		y = NULL;
	}

	Point(float t)
	{
		x = (int)t;
		y = (int)t + 4;
	}

	int Get_X()
	{
		return x;
	}
	int Get_Y()
	{
		return y;
	}
};

template <class T> class DynArray
{
	T* arr;
	int size;
public:
	DynArray(int sizeP) : arr{ new T[sizeP] {} }, size{ sizeP }{}
	DynArray() : DynArray(5) {}
	DynArray(const DynArray& object): arr{ new T[object.size] }, size{ object.size }
	{
		for (int i{ 0 }; i < size; ++i)
		{
			arr[i] = object.arr[i];
		};
	}
	int getElem(int idx) { return arr[idx]; }
	void setElem(int idx, int val) { arr[idx] = val; }
	void print();
	void randomize();
	~DynArray()
	{
		delete[] arr;
	}
	DynArray<T> AddElement(T num);
	DynArray<T> DellElement(T num);
	void SumElement();
};

template <class T>
void DynArray<T>::print()
{
	for (int i = 0 ; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << "\n";
}
template <class T>
void DynArray<T>::randomize()
{
	for (int i = 0 ; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
template <class T>
DynArray<T> DynArray<T>::AddElement(T num)
{
	DynArray <T> temp = size + 1;

	for (int i = 0; i < temp.size; i++)						
	{
		temp.arr[i] = arr[i];
		if (i == temp.size - 1)
		{
			temp.arr[i] = num;
		}
	}
	this->~DynArray();

	arr = new T[temp.size];
	size = temp.size;

	for (int i = 0; i < size; i++)
	{
		arr[i] = temp.arr[i];
	}
	return *this;
}
template <class T>
DynArray<T> DynArray<T>::DellElement(T num)
{
	DynArray <T> temp = size - num;

	for (int i = 0; i < temp.size; i++)
	{
		temp.arr[i] = arr[i];
		if (i == temp.size - 1)
		{
			temp.arr[i] = num;
		}
	}
	this->~DynArray();

	arr = new T[temp.size];
	size = temp.size;

	for (int i = 0; i < size; i++)
	{
		arr[i] = temp.arr[i];
	}
	return *this;
}
template <class T>
void DynArray<T>::SumElement()	// метод для расчета суммы элементов этого массива
{
	DynArray <T> Temp = size;
	float sum = NULL;
	for (size_t i = 0; i < Temp.size; i++)
	{
		sum += arr[i];
	}
	std::cout << "Sum = " << sum << std::endl;
}
float operator+=(float& temp_a, Point& poi_temp)     
{
	temp_a = temp_a + poi_temp.Get_X() + poi_temp.Get_Y();
	return temp_a;
}
std::ostream& operator<<(std::ostream& out, Point& poi_temp)
{
	out << poi_temp.Get_X() << ' ' << poi_temp.Get_Y() << ' ';
	return out;
}
