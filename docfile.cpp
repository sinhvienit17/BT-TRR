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
}
main()
{
	DocFile(W);
	return 0;
}
