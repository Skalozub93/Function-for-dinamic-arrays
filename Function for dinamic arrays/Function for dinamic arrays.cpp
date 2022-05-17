#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
// проверка корректного значения
void check_size(T& size);

template <typename T>
// заполнение массива случайными числами 
void filling(T*& ar, T& size);

template <typename T>
// заполнение массива одним определённым числом
void fill_array(T*& ar, int& size, T number);

template <typename T>
// функция по освобождению памяти из массива
void free_memory(T& ar, int size);

template <typename T>
// добавление элемента в начало массива
void add_to_begin(T*& ar, int size, T number);

template <typename T>
// добавление элемента в середину массива 
void add_to_middle(T*& ar, int& size, int number);

template <typename T>
// удаление последнего элемента по индексу
void del_end(T*& ar, int& size, T number);

template <typename T>
// вставка элемента по индексу
void insert_element(T*& ar, int& size, T number, unsigned int index);

int main()
{
	setlocale(0, "RUS");
	srand(time(0));
    int size;
	cin >> size;
	int* ar = new int[size];
	//filling(ar, size);
	//cout << "\n\n";
	//free_memory(ar, size);
	cout << "Вставляем элемент" << "\n";
	insert_element(ar, size, 10, 2);
	delete[] ar;
}

template <typename T>
void check_size(T& size)
{
	if (size <= 0 || size >= 10000)
	{
		cout << "Error size!" << "\n";
		return;

		throw "Error size!\n";

		size = 10;
	}
}
template <typename T>
// заполнение массива случайными числами 
void filling(T*& ar, T& size)
{
	for (int i = 0; i < size; i++)
	{
		ar[i] = rand() % 20;
	}

	for (int j = 0; j < size; j++)
	{
		cout << ar[j] << ", ";
	}

}
template <typename T>
// заполнение массива одним определённым числом
void fill_array(T*& ar, int& size, T number = 0)
{

	for (int i = 0; i < size; i++)
	{
		ar[i] = number;
	}

	for (int j = 0; j < number; j++)
	{
		cout << ar[j] << ", ";
	}
}
template <typename T>
// функция по освобождению памяти из массива
void free_memory(T& ar, int size)
{
	check_size(size);
	int* temp = new int[size];
	delete[] temp;
	cout << ar << ", " << "\n";
}
template <typename T>
// добавление элемента в начало массива
void add_to_begin(T*& ar, int size, T number)
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i + 1] = ar[i];
	}
	temp[0] = number;
	delete[] ar;
	ar = temp;
	size++;
	for (int j = 0; j < size; j++)
	{
		cout << temp[j] << ", ";
	}
}
template <typename T>
// добавление элемента в середину массива 
void add_to_middle(T*& ar, int& size, int number)
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		temp[i] = ar[i];
	}
	temp[size / 2] = number;
	delete[] ar;
	ar = temp;
	for (int j = 0; j < size; j++)
	{
		cout << temp[j] << ", ";
	}
}
template <typename T>
// удаление последнего элемента по индексу
void del_end(T*& ar, int& size, T number)
{
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = ar[i];
	}
	delete[] ar;
	ar = temp;
	for (int i = 0; i < size; i++)
	{
		cout << temp[i] << ", ";
	}
}

template <typename T>
// вставка элемента по индексу
void insert_element(T*& ar, int& size, T number, unsigned int index)
{
	size++;
	T* temp = new T [size];
	for (int i = 0; i < size; i++)
	{
		if (i < index)
			temp[i] = ar[i];
		else if (i == index)
			temp[i] = number;
		else
			temp[i] = ar[i - 1];
	}
	delete[] ar;
	ar = temp;
	for (int i = 0; i < size; i++)
	{
		cout << temp[i] << ", ";
	}
}


