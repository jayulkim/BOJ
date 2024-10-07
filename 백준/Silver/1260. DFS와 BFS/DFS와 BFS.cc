#include <bits/stdc++.h>
using namespace std;
int visited[1001];
vector<int>graph[1001];
void dfs(int start)
{
	visited[start] = 1;
	cout << start << ' ';
	for (auto& i : graph[start])
	{
		if (visited[i] == 0)
		{
			dfs(i);
		}
	}
}
void bfs(int start)
{
	queue<int>q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		cout << temp << ' ';
		for (auto& i : graph[temp])
		{
			if (visited[i] == 0)
			{
				q.push(i);
				visited[i] = 1;
			}
		}		
	}
}

int main(void)
{
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(k);
	memset(visited, 0, sizeof(visited));
	cout << '\n';
	bfs(k);
	return 0;
}