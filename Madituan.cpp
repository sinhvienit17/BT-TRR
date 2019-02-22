#include<iostream>
#include<iomanip>
#define max 15
using namespace std;
int n=8,x,y,k=0,solution[max][max] = {0};
int X[8] = {-2, -2, -1, -1,  1,  1,  2,  2};
int Y[8] = {-1,  1,  2, -2,  2, -2,  1, -1};
void out()
{
	for (int i=0;i<n;i++)
		{
				for (int j=0;j<n;j++)
				cout << solution[i][j] << "\t";
		  		cout << endl;	
			
		}
}
void nextstep(int x, int y)
{
	k++;
	solution[x][y] = k;
	for (int i=0;i<8;i++)
		{
			int kx = x+X[i];
			int ky = y+Y[i];
			if (k == n*n)
			{
				out();
				exit(0);
			}		
			if (kx >= 0 && kx < n && ky >= 0 && ky < n && solution[kx][ky] == 0 )
				nextstep(kx, ky);
		}
	k--;
	solution[x][y] = 0;	
} 
main()
{
	cout << "Vui long dien vi tri ban dau cua Quan Ma : ";
	cin >> x >> y; 
	nextstep(x,y);
	cout << "No solution";
}
