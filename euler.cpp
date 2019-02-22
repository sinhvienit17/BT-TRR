#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
#define MAX 50 
#define TRUE 1 
#define FALSE  0 
int A[MAX][MAX], n, u=1; 
void DocFile(int A[MAX][MAX])
{
		ifstream FILE;
	FILE.open("D:\\Code\\BT TRR\\CTEULER.IN.txt",ios_base::in);
	if (FILE.fail() == true)
		{
			cout << "\n File ko ton tai ! ";
		}
	FILE >> n;
	cout << " So dinh cua do thi n = " << n << endl;
	cout << "n=" << n << endl;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			FILE >> A[i][j];
	cout << "Mang trong so W:" << endl;		
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			{
				cout << A[i][j] << "\t";
		 	}
		cout << endl; 	
	}		
	FILE.close();		
}
int Kiemtra(){ 
 int s, d; 
 d=0; 
 for(int i=1; i<=n;i++){ 
  s=0; 
  for(int j=1; j<=n;j++) 
   s+=A[i][j];
  if(s%2) d++; 
 } 
 if(d>0) return(FALSE); 
 return(TRUE); 
} 
void Tim(){ 
 int v, x, top, dCE; 
 int stack[MAX], CE[MAX]; 
 top=1;
 stack[top]=u;
 dCE=0; 
 do { 
  v = stack[top];
  x=1; 
  while (x<=n && A[v][x]==0) 
   x++; 
  if (x>n) {
   dCE++;
   CE[dCE]=v;
   top--; 
  } 
  else {
   top++; 
   stack[top]=x; 
   A[v][x]=0;
   A[x][v]=0; 
  } 
 } while(top!=0); 
 cout<<" Co chu trinh Euler:";
 for(x=dCE; x>0; x--) 
  cout<<(char)(CE[x] + 'a' - 1)<<" ";
} 
main(){ 
 DocFile(A);
 if(Kiemtra()) 
  Tim(); 
 else printf("\n Khong co chu trinh Euler"); 
 getch(); 
} 
