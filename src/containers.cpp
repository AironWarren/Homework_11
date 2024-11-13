#include <iostream>
#include "containers.h"


void ArrayContainer::inputData(int* arr, int size)
{
	setlocale(LC_ALL, "ru");

	this->size = size;
	this->arr = arr;

	for (int i = 0; i < this->size; i++)
	{
		std::cout << "Введите значение элемента массива: ";
		std::cin >> this->arr[i];
		std::cout << std::endl;
	}
}

void ArrayContainer::showData() const
{
	setlocale(LC_ALL, "ru");

	std::cout << "Элементы массива: ";
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->arr[i] << " ";
	}
}

int ArrayContainer::getSize() const
{
	return this->size;
}

bool ArrayContainer::isElemInArray(int elem) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (elem == this->arr[i])
			return true;
	}
	
	return false;
}

int ArrayContainer::getElemPosition(int elem) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (elem == this->arr[i])
			return i;
	}

	return -1;
}

void ArrayContainer::pushBack(int value)
{
	setlocale(LC_ALL, "ru");
	int* copyArr;

	if (this->arr == nullptr)
	{
		std::cout << "Массив не существует, создадим";
		
		copyArr = new int[1];
		copyArr[0] = value;
	}
	else 
	{
		copyArr = new int[this->size + 1];

		for (int i = 0; i < this->size; i++)
		{
			copyArr[i] = this->arr[i];
		}

		this->size++;
		copyArr[this->size - 1] = value;
	}

	delete[] this->arr;
	this->arr = copyArr;
}

void ArrayContainer::pushBack(ArrayContainer array)
{
	setlocale(LC_ALL, "ru");

	if (this->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	if (array.arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	int* copyArr = new int[this->size + array.size];

	for (int i = 0; i < this->size; i++)
	{
		copyArr[i] = this->arr[i];
	}

	for (int i = this->size; i < this->size + array.size; i++)
	{
		copyArr[i] = array.arr[i - this->size];
	}

	this->size += array.size;

	delete[] this->arr;
	this->arr = copyArr;
}

void ArrayContainer::pushFront(int value)
{
	setlocale(LC_ALL, "ru");

	if (this->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	int* copyArr = new int[this->size + 1];

	for (int i = 1; i < this->size + 1; i++)
	{
		copyArr[i] = this->arr[i - 1];
	}

	this->size++;
	copyArr[0] = value;

	delete[] this->arr;
	this->arr = copyArr;
}

void ArrayContainer::pushFront(ArrayContainer array)
{
	setlocale(LC_ALL, "ru");

	if (this->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}
	
	if (array.arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	int* copyArr = new int[this->size + array.size];

	for (int i = array.size; i < this->size + array.size; i++)
	{
		copyArr[i] = this->arr[array.size];
	}

	for (int i = 0; i < array.size; i++)
	{
		copyArr[i] = array.arr[i];
	}

	this->size += array.size;

	delete[] this->arr;
	this->arr = copyArr;
}

void ArrayContainer::pushOnSelectedPos(int value, int pos)
{
	setlocale(LC_ALL, "ru");

	if (this->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	if (this->size < pos)
	{
		std::cout << "Позиция привышает размер массива";
		return;
	}

	int* copyArr = new int[this->size + 1];

	for (int i = 0; i < pos; i++)
	{
		copyArr[i] = this->arr[i];
	}

	copyArr[pos] = value;

	for (int i = pos + 1; i < this->size + 1; i++)
	{
		copyArr[i] = this->arr[i - 1];
	}

	this->size++;

	delete[] this->arr;
	this->arr = copyArr;
}

void ArrayContainer::pushOnSelectedPos(ArrayContainer array, int pos)
{
	setlocale(LC_ALL, "ru");

	if (this->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	if (array.arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	int* copyArr = new int[this->size + array.size];

	for (int i = 0; i < pos; i++)
	{
		copyArr[i] = this->arr[i];
	}

	for (int i = pos; i < array.size; i++)
	{
		copyArr[i] = array.arr[i - pos];
	}

	for (int i = pos + array.size; i < this->size + array.size; i++)
	{
		copyArr[i] = this->arr[i - array.size];
	}

	this->size++;

	delete[] this->arr;
	this->arr = copyArr;
}

