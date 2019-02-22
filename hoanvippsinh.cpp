#include<iostream>
using namespace std;
int n,k,count,stop,a[10];
void in()
{
	for(int i=1;i<=n;i++)
		a[i]=i;
		count=1;
}
void out()
{
	cout << count <<" \t ";
	for (int i=1;i<=n;i++)
		cout << a[i];
		cout << endl;
}
int islast()
{
	for(int i=1;i<=n;i++)
		if (a[i]!=n-i+1) return 0;
		return 1;
}
void next()
{
	int i=n-1;
	while(i>=1 && a[i]>a[i+1]) i--;
	int j=n;
	while(j>=1 && a[i]>a[j]) j--;
	int temp = a[j];
	a[j] = a[i];
	a[i] = temp;
	int s=i+1;
	int t=n;
	while(s<t)
		{
			temp = a[s];
			a[s] = a[t];
			a[t] = temp;
			s++;
			t--;
		}
}
void generate()
{
	in();
	out();
	stop=islast();
	while(stop==0)
		{
			next();
			count++;
			out();
			stop=islast();
		}
}
main()
{
	cout << "n=";
	cin >> n;
//	cout << "k=";
//	cin >> k;
	generate();
	return 0;
}
