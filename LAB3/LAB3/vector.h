#pragma once

using namespace std;

// Объявление класса моего вектора
template <typename T>
class vctor
{
#define NOT_DECREASING 0;
#define NOT_INCREASING 1;
public:
	vctor();
	vctor(const vctor<T>&);
	int Search(T x); //Возвращает -1 если не нашел
	void Sort(bool);
	friend void swap(T& a, T& b);
	void Add(T el);// Для добавления нового элемента будем расширять вектор
	void Del(T num);// Для удаления элемента вектор будем сужать
	int Size() { return size; }
	void Show();
	T& operator[ ] (int i);
	vctor<T>& operator =(vctor&);


private:
	T* vec; // Массив, B котором будут храниться элементы вектора
	unsigned int size; // Его размер 

	/*ХОЧЕШЬ ОБРАТИТЬСЯ К ПОСЛЕДНЕМУ - size - 1*/

	int VectorMinIndexCurrent(unsigned int);

	int VectorMaxIndexCurrent(unsigned int i);




};


// БЛОК МЕТОДОВ ВЕКТОРА
//---------------------------------------------------------------------



template <typename T> // Поиск минимального с текущего 
int vctor<T> ::VectorMinIndexCurrent(unsigned int i)
{
	int imin = i;
	for (i; i < size; i++)
	{
		if (vec[i] < vec[imin])
			imin = i;
	}
	return imin;
}

template <typename T>
vctor<T>::vctor(const vctor& a) : size(a.size)
{
	vec = new int[size];
	for (int i = 0; i < size; i++)
	{
		vec[i] = a.vec[i];
	}
}

template <typename T> // Поиск максимального с текущего
int vctor<T> ::VectorMaxIndexCurrent(unsigned int i)
{
	int imax = i;
	for (i; i < size; i++)
	{
		if (vec[i] > vec[imax])
			imax = i;
	}
	return imax;
}

template <typename T> // Сортировка
void vctor<T> ::Sort(bool sorting)
{
	if (!sorting)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			int imax = VectorMinIndexCurrent(i);
			swap(vec[i], vec[imax]);
		}
	}
	else
	{
		for (unsigned int i = 0; i < size; i++)
		{
			int imax = VectorMaxIndexCurrent(i);
			swap(vec[i], vec[imax]);
		}
	}
}

template <typename T> // поиск
int vctor<T> ::Search(T x)
{
	for (size_t i = 0; i < size; i++)
	{
		if (vec[i] == x)
		{
			return i;
		}
	}
	return -1;
}

template <typename T> // мой дружественный свап
void swap(T& a, T& b)
{
	T t;
	t = a;
	a = b;
	b = t;
	delete t;
}

template<typename T> // Конструктор без параметров
vctor<T> ::vctor()
{
	vec = new T[0];
	size = 0;
}

template<typename T> // Добавление элемента
void vctor<T> ::Add(T el) // Для добавления нового элемента будем расширять вектор
{
	size++;
	T* temp = new T[size];// Новый массив размера +1
	for (int i = 0; i < size - 1; i++)// Копируем все элементы старого в новый
	{
		temp[i] = vec[i];
	}
	temp[size - 1] = el;// И добавляем требуемый элемент
	delete[]vec;
	vec = temp;
}

template<typename T> // Удаление элемента
void vctor<T>::Del(T num)// Для удаления элемента вектор будем сужать
{
	size--;
	int i = 0;
	/*if (num >= size)
	{
		return;
	}*/
	T* temp = new T[size];// Новый массив размера -1
	for (; vec[i] != num; i++)// Копируем всё, что до удаляемого элемента
	{
		temp[i] = vec[i];
	}
	for (i++; i < size + 1; i++)//и после него
	{
		temp[i - 1] = vec[i];
	}

	delete[]vec;
	vec = temp;
}

template<typename T> // Вывод в консоль 
void vctor<T>::Show()
{
	for (int i = 0; i < size; i++)
	{
		cout << vec[i] << " ";
	}
}

template<typename T> // перегрузка []
T& vctor<T> :: operator[ ] (int i)
{
	if (i < 0 or i >= size)
	{
		cout << "WRONG!\n";
		exit(1);
	}
	return vec[i];

}

template<typename T>
vctor<T>& vctor<T>:: operator=(vctor& a) {
	//this ->size = a.size;
	this->size = a.size;
	this->vec = new T[size];
	for (int i = 0; i < size; i++)
	{
		this->vec[i] = a.vec[i];
	}
	return *this;
}

//-------------------------------------------------------------------
