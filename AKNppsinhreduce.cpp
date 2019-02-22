#include<iostream>
using namespace std;
int n,k,countv=0,countc=0,dem=0,a[10],s[10];
void out()
{
	//cout << ++dem << "\t";
	for(int i=1;i<=k;i++)
		cout << s[a[i]];
		cout << endl;
}
int C(int n,int k)
{
	if (k==0 ||k==n) return 1;
	return C(n-1,k-1) +C(n-1,k);
}
int fact(int k)
{
	if (k==0) return 1;
	return k*fact(k-1);
}
void gen()
{
	int i,j,ii,jj,kk,tam;	
	countc++;
	countv=0;
	for(ii=1;ii<=k;ii++) a[ii]=ii;
	countv++;out();
	while(countv < fact(k))
		{
			ii=k-1;
			while(a[ii]>a[ii+1]) ii--;
			jj=k;
			while(a[jj]<a[ii]) jj--;
			tam = a[ii];
			a[ii] = a[jj];
			a[jj] = tam;
			jj=ii+1; kk=k;
			while(jj<kk)
				{
					tam = a[jj];
					a[jj] = a[kk];
					a[kk] = tam;
					jj++;
					kk--;
				}
			countv++;out();	
		}
}
main()
{
	int i,j,ii,jj,kk,tam;
	cout << "n & k =";
	cin >> n >> k;
	for(i=1;i<=k;i++) s[i]=i;
	gen();
	while(countc<C(n,k))
		{
			i=k;while(s[i]==n-k+i) i--;
			s[i]++;
			for(j=i+1;j<=k;j++) s[j]=s[i]-i+j;
			gen();
		}	
		return 0;
}
