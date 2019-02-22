#include<iostream>
using namespace std;
int s[50],kt[50],n,k,count;
void in()
{
	for(int i=0;i<=n;i++)
		kt[i]=1;
}
void out()
{ 
	for(int i=1;i<=k;i++)
		cout << s[i];
		cout << endl;
}
void Try(int i)
{
	for(int j=1;j<=n;j++)
		if(kt[j]==1)
			{
				s[i]=j;
				if (i==k) out();
				else {
						kt[j]=0;
						Try(i+1);
						kt[j]=1;
					 }
			}
}
main()
{
	cout << "n va k =";
	cin >> n >> k;
	in();
	Try(1);
	return 0;
}
