#include <bits/stdc++.h>
using namespace std;
bool visited[100001];
vector<int>graph[100001];
int idx = 0;
int ary[100001];
void dfs(int start)
{
	visited[start] = true;
	ary[start] = ++idx;
	for (auto& i : graph[start])
	{
		if (visited[i] == false)
		{
			dfs(i);
		}
	}
}
int main(void)
{
	int n = 0, m = 0, r = 0;
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (auto& i : graph)
	{
		sort(i.begin(), i.end());
	}
	dfs(r);
	for (int i = 1; i <= n; i++)
	{
		cout << ary[i] << '\n';
	}
}