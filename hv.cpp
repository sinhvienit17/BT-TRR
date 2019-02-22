#include<iostream>
using namespace std;
int s[50],kt[50],n,k,count;
void in()
{
	for(int i=0;i<=n;i++)
		kt[i]=1;
		count = 1;
}
void out()
{ 
	cout << count << " ";
	for(int i=1;i<=n;i++)
		cout << s[i];
		cout << endl;
}
void Try(int i)
{
	if (i>n) {
				out();
				count++;
				}
				
	for(int j=1;j<=n;j++)
		if(kt[j]==1)
			{
				s[i]=j;
				
						kt[j]=0;
						Try(i+1);
						kt[j]=1;
					 
			}
}
main()
{
	cout << "n =";
	cin >> n;
	in();
	Try(1);
	return 0;
}
