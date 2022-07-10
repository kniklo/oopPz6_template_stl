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
	int N = 10;
	vector<int> myVector(N);
	myVector = { 12,9,44,8,-6,77,2,-11,3,999 };
	vector<int>::iterator it;
	it = myVector.begin();
	//выводим элементы
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	//нашли кол-во отрицательных чисел
	int count = 0;
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		if (*i < 0)
		{
			count++;
		}
	}
	cout << "Negative numbers: " << count << endl;

/*
	vector<int>::iterator it2;
	it2 = min_element(myVector.begin(), myVector.end()); //алгоритм stl вернул минимальный ел но мне нужен модуль
	cout << *it2 << endl;
*/
	//поставили it2 на элемент с минимальным модулем
	vector<int>::iterator it2 = myVector.begin();
	int min = myVector[0];
	for (int i = 0; i < myVector.size(); i++)
	{
		if (abs(myVector[i]) < abs(min))
		{
			min = myVector[i];
			advance(it2, i); // не вышло
		}
	}
	cout << "Min: " << min << endl;
	cout << *it2 << endl; // ошибкј



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
