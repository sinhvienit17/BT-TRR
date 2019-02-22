#include<iostream>
using namespace std;
int count,stop,n;
void input(int a[])
{
	count=1;
	for(int i=1;i<=n;i++)
		a[i]=i;
}
void output(int a[])
{
	cout << endl;
	cout << count << "\t";
	for(int i=1;i<=n;i++)
		cout << a[i];
}
int giaithua(int n)
{
	if(n==0 || n==1) return 1; 
	return n*giaithua(n-1);
}
int islast(int a[])
{
	for(int i=1;i<=n;i++) 
		if (a[i]!=n-i+1) return 0;
		return 1;
}
void next(int a[])
{
	int i=n-1;
	while (i>=1 && a[i]>a[i+1]) i--;
	int k=n;
	while(k>=1 && a[i]>a[k]) k--;
		int tam = a[k];
		a[k] = a[i];
		a[i] = tam;
	int j=i+1;
	int s=n;
		while(j<s)	
					{
						tam = a[j];
						a[j] = a[s];
						a[s] = tam; 
						j++;
						s--;
					}
		
}
void generate(int a[])
{
	input(a);
	output(a);
	stop=islast(a);
	while(stop==0)
		{
			count++;
			next(a);
			output(a);
			stop=islast(a);
		}
}
main()
{
	int a[n];
	cout << "n=";
	cin >> n;
	generate(a);
	return 0;
}
