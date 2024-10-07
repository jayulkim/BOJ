#include <bits/stdc++.h>
using namespace std;
queue<int>que;
stack<int>st;
int visited[300001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	que.push(n);
	visited[n] = 1;
	int result = 0;
	while (1)
	{
		while (!que.empty())
		{
			st.push(que.front());
			if (que.front() == k)
			{
				cout << result;
				return 0;
			}
			que.pop();
		}
		while (!st.empty())
		{
			if (visited[st.top() - 1] == 0 && st.top() - 1 >= 0)
			{
				que.push(st.top() - 1);
				visited[st.top() - 1] = 1;
			}
			if (visited[st.top() + 1] == 0 && st.top() + 1 <= 100000)
			{
				que.push(st.top() + 1);
				visited[st.top() + 1] = 1;
			}
			if (visited[st.top() * 2] == 0 && st.top() * 2 <= 100000)
			{
				que.push(st.top() * 2);
				visited[st.top() * 2] = 1;
			}
			st.pop();
		}
		result++;
	}
	cout << result;
}