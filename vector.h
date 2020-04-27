#pragma once

using namespace std;

// ���������� ������ ����� �������
template <typename T>
class vctor
{
#define NOT_DECREASING 0;
#define NOT_INCREASING 1;
public:
	vctor();
	vctor(const vctor<T>&);
	int Search(T x); //���������� -1 ���� �� �����
	void Sort(bool);
	friend void swap(T& a, T& b);
	void Add(T el);// ��� ���������� ������ �������� ����� ��������� ������
	void Del(T num);// ��� �������� �������� ������ ����� ������
	int Size() { return size; }
	void Show();
	T& operator[ ] (int i);
	vctor<T>& operator =(vctor&);


private:
	T* vec; // ������, B ������� ����� ��������� �������� �������
	unsigned int size; // ��� ������ 

	/*������ ���������� � ���������� - size - 1*/

	int VectorMinIndexCurrent(unsigned int);

	int VectorMaxIndexCurrent(unsigned int i);




};


// ���� ������� �������
//---------------------------------------------------------------------



template <typename T> // ����� ������������ � �������� 
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

template <typename T> // ����� ������������� � ��������
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

template <typename T> // ����������
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

template <typename T> // �����
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

template <typename T> // ��� ������������� ����
void swap(T& a, T& b)
{
	T t;
	t = a;
	a = b;
	b = t;
	delete t;
}

template<typename T> // ����������� ��� ����������
vctor<T> ::vctor()
{
	vec = new T[0];
	size = 0;
}

template<typename T> // ���������� ��������
void vctor<T> ::Add(T el) // ��� ���������� ������ �������� ����� ��������� ������
{
	size++;
	T* temp = new T[size];// ����� ������ ������� +1
	for (int i = 0; i < size - 1; i++)// �������� ��� �������� ������� � �����
	{
		temp[i] = vec[i];
	}
	temp[size - 1] = el;// � ��������� ��������� �������
	delete[]vec;
	vec = temp;
}

template<typename T> // �������� ��������
void vctor<T>::Del(T num)// ��� �������� �������� ������ ����� ������
{
	size--;
	int i = 0;
	/*if (num >= size)
	{
		return;
	}*/
	T* temp = new T[size];// ����� ������ ������� -1
	for (; vec[i] != num; i++)// �������� ��, ��� �� ���������� ��������
	{
		temp[i] = vec[i];
	}
	for (i++; i < size + 1; i++)//� ����� ����
	{
		temp[i - 1] = vec[i];
	}

	delete[]vec;
	vec = temp;
}

template<typename T> // ����� � ������� 
void vctor<T>::Show()
{
	for (int i = 0; i < size; i++)
	{
		cout << vec[i] << " ";
	}
}

template<typename T> // ���������� []
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
