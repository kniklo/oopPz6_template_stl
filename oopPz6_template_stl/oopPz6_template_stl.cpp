// oopPz6_template_stl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	int N = 10;	// длина массива
	vector<int> v1(N);	//инициализаци€ типа vector
	srand(time(NULL));	
	// заполнение массива случайными целыми числами от -K до K
	int K = 100;
	for (int i = 0; i < N; i++)
	{
		v1[i] = rand() % (2 * K) - K;
	}	
	//выводим элементы использу€ <range based for>
	cout << "Origin array:\n";
	for (const int &j : v1)
	{
		cout << j << " ";
	}
	cout << endl << endl;

	// ќЅўјя „ј—“№

	// находим макс и мин элементы на всем массиве и на заданном диапазоне
	int M1 = 3;	// начало диапазона
	int M2 = 8; // конец диапазона
	vector<int>::const_iterator m1 = v1.begin() + M1;
	vector<int>::const_iterator m2 = v1.begin() + M2;
	vector<int> v2(m1, m2);
	cout << "Sub array from " << M1 << " to " << M2 << " indexes\n";
	//выводим элементы использу€ <range based for>
	for (const int& j : v2)
	{
		cout << j << " ";
	}
	cout << endl << endl;

	// минимальные и максимальные значени€
	cout << "Min & Max el's for origin array\n";
	vector<int>::iterator itmin = min_element(v1.begin(), v1.end());
	vector<int>::iterator itmax = max_element(v1.begin(), v1.end());
	cout << *itmin << endl;
	cout << *itmax << endl;
	cout << endl;
	cout << "Min & Max el's for sub array\n";
	itmin = min_element(v2.begin(), v2.end());
	itmax = max_element(v2.begin(), v2.end());
	cout << *itmin << endl;
	cout << *itmax << endl;
	cout << endl;

	//сортировка массивов
	vector<int> v3(v1.begin(), v1.end());
	sort(v3.begin(), v3.end());
	//выводим элементы использу€ <range based for>
	cout << "Sorted origin array:\n";
	for (const int& j : v3)
	{
		cout << j << " ";
	}
	cout << endl << endl;
	vector<int> v4(v2.begin(), v2.end());
	sort(v4.begin(), v4.end());
	reverse(v4.begin(), v4.end());
	//выводим элементы использу€ <range based for>
	cout << "Sorted sub array in reverse order:\n";
	for (const int& j : v4)
	{
		cout << j << " ";
	}
	cout << endl << endl;

	//вставка v2 в v3
	int pos = 5;
	v3.insert(v3.begin() + pos, v2.begin(), v2.end());
	cout << "inserted sub array into sorted origin array from position :" << pos << " \n";
	for (const int& j : v3)
	{
		cout << j << " ";
	}
	cout << endl << endl;

	// и удал€ем вставленное
	cout << "remove last inserted elements :\n";
	v3.erase(v3.begin() + pos, v3.begin() + pos + v2.size());
	for (const int& j : v3)
	{
		cout << j << " ";
	}
	cout << endl << endl;

	// »Ќƒ»¬»ƒ”јЋ№Ќјя „ј—“№
	// количество отрицательных элементов
	int count = 0;
	for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
	{
		if (*i < 0)
		{
			count++;
		}
	}
	cout << "Negative numbers count: " << count << endl << endl;

	// сумма модулей элементов, следующих за минимальным
	vector<int>::iterator it2;
	it2 = min_element(v1.begin(), v1.end()); 
	int sum = 0;
	for (vector<int>::iterator i = it2 + 1; i != v1.end(); i++)
	{
		sum = sum + abs(*i);
	}
	cout << "Sum of elements modules following " << *it2 << " is: " << sum << endl << endl;
	
	// заменим отрицательыне элементы их квадратами и отсортируем массив
	cout << "Replace negative numbers by origin array it squarers and sort it\n";
	for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
	{
		if (*i < 0)
		{
			*i=*i**i;
		}
	}
	sort(v1.begin(), v1.end());
	//выводим элементы использу€ <range based for>
	for (const int& j : v1)
	{
		cout << j << " ";
	}
	cout << endl << endl;	
}


