#include <bits/stdc++.h>
using namespace std;

deque<int>dq;
vector<int>v;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int	n = 0;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int count = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		switch (v[i])
		{
			case 1:
			{
				dq.push_front(count);
				count++;
				break;
			}
			case 2:
			{
				int temp = dq.front();
				dq.pop_front();
				dq.push_front(count);
				dq.push_front(temp);
				count++;
				break;
			}
			case 3:
			{
				dq.push_back(count);
				count++;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << dq.front() << ' ';
		dq.pop_front();
	}
}