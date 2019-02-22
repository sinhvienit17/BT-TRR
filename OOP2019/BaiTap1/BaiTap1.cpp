// BaiTap1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int n, m;
int **a;
void in(int **a)
{
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "A[" << i <<"][" << j <<"]=";
			cin >> a[i][j];
		}
	}
}
void out(int **a)
{
	cout << "Mang A la :" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " \t ";
		cout << endl;
	} 
}
void minmax(int **a)
{
	int min = a[0][0];
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (min > a[i][j]) min = a[i][j];
			if (max < a[i][j]) max = a[i][j];
		}
	}
	cout << "min=" << min << endl;
	cout << "max=" << max << endl;
	for (int i = 0; i < n; i++)
	{
		int minrow = a[i][0];
		int maxrow = a[i][0];
		for (int j = 0; j < m; j++)
		{
			
			if (minrow > a[i][j]) minrow = a[i][j];
			if (maxrow < a[i][j]) maxrow = a[i][j];
		}
		cout << "minrow" << i+1 << "=" << minrow << endl;
		cout << "maxrow" << i+1 << "=" << maxrow << endl;
	}
}
int main()
{
	cout << "Nhap so hang n=";
	cin >> n;
	cout << "Nhap so cot m=";
	cin >> m;
	int **a = new int *[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	in(a);
	out(a);
	minmax(a);
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	system("pause");
}
