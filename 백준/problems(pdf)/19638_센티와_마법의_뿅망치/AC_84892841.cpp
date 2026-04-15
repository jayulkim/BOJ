#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, h = 0, t = 0;
	cin >> n >> h >> t; 
	priority_queue<int>pq;
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;
		pq.push(num);
	}
	for (int i = 0; i < t; i++)
	{
		int temp = pq.top();
		if (temp < h)
		{
			cout << "YES" << '\n' << i;
			return 0;
		}
		if (temp > 1)
		{
			pq.pop();
			pq.push(temp / 2);
		}
	}
	if (pq.top() < h)
	{
		cout << "YES" << '\n' << t;
	}
	else
	{
		cout << "NO" << '\n' << pq.top();
	}
	return 0;
}