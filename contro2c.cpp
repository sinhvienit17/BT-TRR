// BaiTap1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


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
			cout << a[i][j] << "  ";
		cout << endl;
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
	return 0;
	system("pause");
}

