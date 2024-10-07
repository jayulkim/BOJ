#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector<int>graph[100001];
void insert(int start, int end)
{
	graph[start].push_back(end);
	graph[end].push_back(start);
}
int result[100001] = { 0, };
int visited[100001] = { 0, };
void dfs(int start)
{
	visited[start] = 1;
	for (auto& i : graph[start])
	{
		if (visited[i] == 0)
		{
			result[i] = start;
			dfs(i);
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		insert(start, end);
	}
	dfs(1);
	for (int i = 2; i <= n; i++)
	{
		cout << result[i] << '\n';
	}
}