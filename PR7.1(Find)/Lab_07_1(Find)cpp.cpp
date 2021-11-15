// Lab_07_1.cpp
// Вольвенко Іван
// Лабораторна робота № 7.1
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 13

#include<iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
	srand((unsigned)time(NULL));

	int Low = 4;
	int High = 45;

	int rowCount = 9;
	int colCount = 7;

	int** z = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		z[i] = new int[colCount];

	Create(z, rowCount, colCount, Low, High);
	Print(z, rowCount, colCount);
	Sort(z, rowCount, colCount);
	Print(z, rowCount, colCount);

	int S = 0;
	int k = 0;
	Calc(z, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(z, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] z[i];
	delete[] z;

	return 0;
}

void Create(int** mas, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			mas[i][j] = Low + rand() % (High - Low + 1);
		}
	}
}

void Print(int** mas, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << setw(4) << mas[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Sort(int** mas, const int rowCount, const int colCount)
{
	for (int j0 = 0; j0 < colCount-1; j0++)
	{
		for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
		{
			if ((mas[0][j1] < mas[0][j1 + 1])
				||
				(mas[0][j1] == mas[0][j1 + 1] &&
					mas[1][j1] > mas[1][j1 + 1])
				||
				(mas[0][j1] == mas[0][j1 + 1] &&
					mas[1][j1] == mas[1][j1 + 1] &&
					mas[2][j1] < mas[2][j1 + 1]))
				Change(mas, j1, j1 + 1, rowCount);
		}
	}
}

void Change(int** mas, int col1, int col2, const int rowCount)
{
	int tmp;
	for (int i = 0; i < rowCount; i++)
	{
		tmp = mas[i][col1];
		mas[i][col1] = mas[i][col2];
		mas[i][col2] = tmp;
	}
}

void Calc(int** mas, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			if (mas[i][j] %2==0 && !(i % 2 != 0 || j %2 != 0))
			{
				S += mas[i][j];
				k++;
				mas[i][j] = 0;
			}
	}
}