#include <bits/stdc++.h>
using namespace std;
vector<int>graph[10001];
bool visited[10001];
int result = 0;
void dfs(int start)
{
	visited[start] = true;
	result++;
	for (auto& i : graph[start])
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}
}
int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;
	int Max = 0;
	vector<int>solve;
	for (int i = 0; i < m; i++)
	{
		int start = 0, end = 0;
		cin >> end >> start;
		graph[start].push_back(end);
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(i);
		if (Max < result)
		{
			vector<int>().swap(solve);
			Max = result;
			solve.push_back(i);
		}
		else if (Max == result)
		{
			solve.push_back(i);
		}
		result = 0;
		memset(visited, false, sizeof(visited));
	}
	sort(solve.begin(), solve.end());
	for (auto& i : solve)
	{
		cout << i << ' ';
	}
	return 0;
}