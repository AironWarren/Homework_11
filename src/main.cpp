﻿#include <iostream>
#include "functions.h"


int main()
{
	setlocale(LC_ALL, "ru");

	ArrayContainer container1, container2, concontainer;

	int n1 = 0; int n2 = 0;

	std::cout << "Введите размер массива: ";
	std::cin >> n1;
	std::cout << std::endl;

	std::cout << "Введите размер массива: ";
	std::cin >> n2;
	std::cout << std::endl;


	int* arr1 = new int[n1];
	int* arr2 = new int[n2];

	container1.inputData(arr1, n1);
	std::cout << std::endl;
	container1.showData();

	container2.inputData(arr2, n2);
	std::cout << std::endl;
	container2.showData();

	concontainer = intersecData(container1, container2);

	return 0;
}