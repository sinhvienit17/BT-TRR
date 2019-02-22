#include <iostream>
using namespace std;
int n,k;
int a[50],b[50];
void out()
{
	for (int t=1;t<=k;t++)
	cout<<a[t]<<' ';
	cout<<endl;
}
int ck(int a[])
{
	for (int t=1;t<=k;t++) if (a[t]!=b[t]) return 0;
	return 1;
}
void init()
{
	for (int i=1;i<=k;i++) 
	{
		a[i]=1;
		b[i]=n;
	}
}
void gen()
{
	int i=k;
	while(a[i]==n && i>=1) i--;
	a[i]++;
	for (int j=i+1;j<=k;j++) a[j]=1;
	out();
}
int main()
{
	cin>>n>>k;
	init();
	out();
	while (ck(a)==0)
	{
		gen();
		
	}
	return 0;
}
