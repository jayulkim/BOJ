#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<int, int>a, const pair<int, int>b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<int, int>>v;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end(), compare);
	for (auto& i : v)
	{
		cout << i.first << ' ' << i.second << '\n';
	}
}