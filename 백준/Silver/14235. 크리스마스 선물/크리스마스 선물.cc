#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	priority_queue<int>pq;
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		cin >> a;
		if (a == 0)
		{
			if (pq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			for (int j = 0; j < a; j++)
			{
				int num = 0;
				cin >> num;
				pq.push(num);
			}
		}
	}
	return 0;
}