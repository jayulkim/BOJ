#include <bits/stdc++.h>
using namespace std;
bool visited[51];
vector<int>graph[51];
int result = 0;
void dfs(int start, int del)
{
	if (graph[start].size() == 0 || (graph[start].size() == 1 && graph[start].back() == del))
	{
		result++;
	}
	visited[start] = true;
	for (auto& i : graph[start])
	{
		if (visited[i] == false && i != del)
		{
			dfs(i, del);
		}
	}
}
int main(void)
{
	int n = 0;
	cin >> n;
	int root = 0;
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;
		if (num == -1)
		{
			root = i;
		}
		else
		{
			graph[num].push_back(i);
		}
	}
	int del = 0;
	cin >> del;
	if (del == root)
	{
		cout << 0;
		return 0;
	}
	dfs(root, del);
	cout << result;
	return 0;
}