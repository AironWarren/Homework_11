#include "test.h"
#include <iostream>

class Testing::Impl
{
public:
    explicit Impl()
    {
        name = "Ne Igor";
        arr = nullptr;
        size = 0;
    }

    Impl(std::string _name)
    {
        name = _name;
        arr = nullptr;
        size = 0;
    }

    void welcomeMessage()
    {
        std::cout << "Welcome, " << name << std::endl;
    }

    std::string name;
    int* arr;
    int size;
};


Testing::Testing(std::string name): m_pData(std::make_unique<Impl>(name))
{
    m_pData->welcomeMessage();
}

Testing::Testing() : m_pData(std::make_unique<Impl>())
{
    m_pData->welcomeMessage();
}

Testing::~Testing() = default;

std::string Testing::getData() const
{
    return m_pData->name;
}

void Testing::inputData(int* arr, int size)
{
    setlocale(LC_ALL, "ru");

    m_pData->size = size;
    m_pData->arr = arr;

    for (int i = 0; i < m_pData->size; i++)
    {
        std::cout << "Введите значение элемента массива: ";
        std::cin >> m_pData->arr[i];
        std::cout << std::endl;
    }
}

void Testing::showData() const
{
    setlocale(LC_ALL, "ru");

    std::cout << "Элементы массива: ";
    for (int i = 0; i < m_pData->size; i++)
    {
        std::cout << m_pData->arr[i] << " ";
    }
}

int Testing::getSize() const
{
    return m_pData->size;
}

bool Testing::isElemInArray(int elem) const
{
	for (int i = 0; i < m_pData->size; i++)
	{
		if (elem == m_pData->arr[i])
			return true;
	}

	return false;
}

int Testing::getElemPosition(int elem) const
{
	for (int i = 0; i < m_pData->size; i++)
	{
		if (elem == m_pData->arr[i])
			return i;
	}

	return -1;
}

void Testing::pushBack(int value)
{
	setlocale(LC_ALL, "ru");
	int* copyArr;

	if (m_pData->arr == nullptr)
	{
		std::cout << "Массив не существует, создадим";

		copyArr = new int[1];
		copyArr[0] = value;
	}
	else
	{
		copyArr = new int[m_pData->size + 1];

		for (int i = 0; i < m_pData->size; i++)
		{
			copyArr[i] = m_pData->arr[i];
		}

		m_pData->size++;
		copyArr[m_pData->size - 1] = value;
	}

	delete[] m_pData->arr;
	m_pData->arr = copyArr;
}

void Testing::pushBack(Testing array)
{
	setlocale(LC_ALL, "ru");

	if (m_pData->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	if (array.m_pData->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	int* copyArr = new int[m_pData->size + array.m_pData->size];

	for (int i = 0; i < m_pData->size; i++)
	{
		copyArr[i] = m_pData->arr[i];
	}

	for (int i = m_pData->size; i < m_pData->size + array.m_pData->size; i++)
	{
		copyArr[i] = array.m_pData->arr[i - m_pData->size];
	}

	m_pData->size += array.m_pData->size;

	delete[] m_pData->arr;
	m_pData->arr = copyArr;
}

void Testing::pushFront(int value)
{
	setlocale(LC_ALL, "ru");

	if (m_pData->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	int* copyArr = new int[m_pData->size + 1];

	for (int i = 1; i < m_pData->size + 1; i++)
	{
		copyArr[i] = m_pData->arr[i - 1];
	}

	m_pData->size++;
	copyArr[0] = value;

	delete[]  m_pData->arr;
	m_pData->arr = copyArr;
}

void Testing::pushFront(Testing array)
{
	setlocale(LC_ALL, "ru");

	if (m_pData->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	if (array.m_pData->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	int* copyArr = new int[m_pData->size + array.m_pData->size];

	for (int i = array.m_pData->size; i < m_pData->size + array.m_pData->size; i++)
	{
		copyArr[i] = m_pData->arr[array.m_pData->size];
	}

	for (int i = 0; i < array.m_pData->size; i++)
	{
		copyArr[i] = array.m_pData->arr[i];
	}

	m_pData->size += array.m_pData->size;

	delete[] m_pData->arr;
	m_pData->arr = copyArr;
}

void Testing::pushOnSelectedPos(int value, int pos)
{
	setlocale(LC_ALL, "ru");

	if (m_pData->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	if (m_pData->size < pos)
	{
		std::cout << "Позиция привышает размер массива";
		return;
	}

	int* copyArr = new int[m_pData->size + 1];

	for (int i = 0; i < pos; i++)
	{
		copyArr[i] = m_pData->arr[i];
	}

	copyArr[pos] = value;

	for (int i = pos + 1; i < m_pData->size + 1; i++)
	{
		copyArr[i] = m_pData->arr[i - 1];
	}

	m_pData->size++;

	delete[] m_pData->arr;
	m_pData->arr = copyArr;
}

void Testing::pushOnSelectedPos(Testing array, int pos)
{
	setlocale(LC_ALL, "ru");

	if (m_pData->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	if (array.m_pData->arr == nullptr)
	{
		std::cout << "Массив не существует";
		return;
	}

	int* copyArr = new int[m_pData->size + array.m_pData->size];

	for (int i = 0; i < pos; i++)
	{
		copyArr[i] = m_pData->arr[i];
	}

	for (int i = pos; i < array.m_pData->size; i++)
	{
		copyArr[i] = array.m_pData->arr[i - pos];
	}

	for (int i = pos + array.m_pData->size; i < m_pData->size + array.m_pData->size; i++)
	{
		copyArr[i] = m_pData->arr[i - array.m_pData->size];
	}

	m_pData->size++;

	delete[] m_pData->arr;
	m_pData->arr = copyArr;
}