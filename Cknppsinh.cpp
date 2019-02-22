#include<iostream>
using namespace std;
int count,stop,n;
void input(int a[], int k)
{
	count=1;
	for(int i=1;i<=k;i++)
		a[i]=i;
}
void output(int a[], int k)
{
	cout << endl;
	cout << count << "\t";
	for(int i=1;i<=k;i++)
		cout << a[i];
}
int islast(int a[], int k)
{
	for(int i=k;i>=1;i--) 
		if (a[i]!=n-k+i) return 0;
		return 1;
}
void next(int a[], int k)
{
	int i=k;
	while (i>=1 && a[i]==n-k+i) i--;
	a[i]++;
	for(int j=i+1;j<=k;j++)
		a[j]=a[i]-i+j;
}
void generate(int a[], int k)
{
	input(a,k);
	output(a,k);
	stop=islast(a,k);
	while(stop==0)
		{
			count++;
			next(a,k);
			output(a,k);
			stop=islast(a,k);
		}
}
main()
{
	int k,a[k];
	cout << "n=";
	cin >> n;
	cout << "k=";
	cin >> k;
	generate(a,k);
	return 0;
}
