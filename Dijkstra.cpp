#include<iostream>
using namespace std;
#include<fstream>
#define max 100
int n,D,C,W[max][max];
void DocFile(int W[max][max])
{
		ifstream FILE;
	FILE.open("D:\\Code\\BT TRR\\Dothi.inp.txt",ios_base::in);
	if (FILE.fail() == true)
		{
			cout << "\n File ko ton tai ! ";
		}
	FILE >> n >> D >> C;
	cout << "n=" << n << endl;
	cout << "D=" << D << endl; 
	cout << "C=" << C << endl; 	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			FILE >> W[i][j];
	cout << "Mang trong so W:" << endl;		
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
				cout << W[i][j] << "\t";
		 	}
		cout << endl; 	
	}		
	FILE.close();	
	D--;C--;		
}
void Dijkstra(int W[max][max], int n, int D, int C)
{
	char Danhdau[max];
	int Nhan[max], truoc[max], px, min;
	for (int i=0;i<n;i++)
	{
		Nhan[i] = max;
		Danhdau[i]=0;
		truoc[i]=D;
	}
	Nhan[D] = 0;
	
	Danhdau[D] = 1;
	px = D;
	while (px != C)
		{
		for (int j=0;j<n;j++)
		if (W[px][j] > 0 && Nhan[j] > W[px][j] + Nhan[px]&& Danhdau[j] == 0)
		{
			Nhan[j] = W[px][j]+Nhan[px];
			truoc[j] = px;
			
		}
		min = max;
		for (int j=0;j<n;j++)
			if (min > Nhan[j] && Danhdau[j]==0)
			{
				min = Nhan[j];
				px=j;
			}
			Danhdau[px]=1;
		}
		cout << "Duong di ngan nhat la:" << Nhan[C] << endl;
		cout << C+1 << "<--" << truoc[C]+1;
		int k=truoc[C];
		while(k != D)
		{
			k = truoc[k];
			cout << "<--" << k+1  ;
		}
}
main()
{
	DocFile(W);
	Dijkstra(W,n,D,C);
	return 0;
}
