#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	priority_queue<int>pq;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (i != 0)
		{
			pq.push(v[i]);
		}
	}
	int count = 0;
	while (!pq.empty() && pq.top() >= v[0])
	{
		int temp = pq.top() - 1;
		v[0]++;
		pq.pop();
		pq.push(temp);
		count++;
	}
	cout << count;
	return 0;
}