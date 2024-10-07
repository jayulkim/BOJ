#include <bits/stdc++.h>
using namespace std;
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
	sort(v.begin(), v.end());
	for (auto& i : v)
	{
		cout << i.first << ' ' << i.second << '\n';
	}
}