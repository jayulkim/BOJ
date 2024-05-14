#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll>m;
int result = 0;
void bfs(ll start, ll end)
{
	vector<ll>v1;
	vector<ll>v2;
	v1.push_back(start);
	m.insert({ start, 0 });
	while (1)
	{
		if (v1.empty() && v2.empty())
		{
			cout << -1;
			return;
		}
		while (!v1.empty())
		{
			ll temp = v1.back();
			if (temp == end)
			{
				cout << result + 1;
				return;
			}
			v1.pop_back();
			if (m.find(temp) == m.end())
			{
				m.insert({ temp, 0 });
			}
			if (m.find(temp * 2) == m.end() && temp * 2 <= end)
			{
				v2.push_back(temp * 2);
				m.insert({ temp * 2, 0 });
			}
			if (m.find(temp * 10 + 1) == m.end() && temp * 10 + 1 <= end)
			{
				v2.push_back(temp * 10 + 1);
				m.insert({ temp * 10 + 1, 0 });
			}
		}
		result++;
		while (!v2.empty())
		{
			ll temp = v2.back();
			if (temp == end)
			{
				cout << result + 1;
				return;
			}
			v2.pop_back();
			if (m.find(temp) == m.end())
			{
				m.insert({ temp, 0 });
			}
			if (m.find(temp * 2) == m.end() && temp * 2 <= end)
			{
				v1.push_back(temp * 2);
				m.insert({ temp * 2, 0 });
			}
			if (m.find(temp * 10 + 1) == m.end() && temp * 10 + 1 <= end)
			{
				v1.push_back(temp * 10 + 1);
				m.insert({ temp * 10 + 1, 0 });
			}
		}
		result++;
	}
}
int main(void)
{
	ll start = 0, end = 0;
	cin >> start >> end;
	bfs(start, end);
}