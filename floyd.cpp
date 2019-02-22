#include<bits/stdc++.h>
#include<fstream>
#define maxn 1005
using namespace std;
int n, m, s, t, f[maxn][maxn], dd[maxn], trc[maxn], c[maxn][maxn], res;
vector<int> e[maxn];
void findgraph()
{
	queue<int> q;
	while (!q.empty()) q.pop();
	dd[s] = 1;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < (int)e[u].size(); i++)
		{
			int v = e[u][i];
			if (dd[v]) continue;
			if (f[u][v] >= c[u][v]) continue;
			trc[v] = u;
			dd[v] = 1;;
			if (v == t)
			{
				return;
			}
			q.push(v);
		}
	}
}

void incflow()
{
	int tmp = 1000000000;
	int v = t;
	while (v != s)
	{
		int u = trc[v];
		tmp = min(tmp, c[u][v] - f[u][v]);
		v = u;
	}
	v = t;
	while (v != s)
	{
		int u = trc[v];
		f[u][v] += tmp;
		f[v][u] -= tmp;
		v = u;
	}
	res += tmp;
}

int main()
{

//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m >> s >> t;
	ifstream FILE;
	FILE.open("D:\\Code\\BT TRR\\LCD.txt",ios_base::in);
	if (FILE.fail() == true)
		{
			cout << "\n File ko ton tai ! ";
		}
	FILE >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int u, v, val;
		cin >> u >> v >> val;
		c[u][v] = val;
		e[u].push_back(v);
		e[v].push_back(u);
	}
		FILE.close();	
	while (1)
	{
		memset(dd, 0, sizeof(dd));
		memset(trc, 0, sizeof(trc));
		findgraph();
		if (trc[t] == 0) break;
		incflow();
	}
	cout << res;
	return 0;
}

