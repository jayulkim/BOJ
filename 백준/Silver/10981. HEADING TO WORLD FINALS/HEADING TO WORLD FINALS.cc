#include <bits/stdc++.h>
using namespace std;
struct info
{
	string school;
	string teamname;
	int plus;
	int minus;
};
bool compare(const info& a, const info& b)
{
	if (a.plus == b.plus)
	{
		return a.minus < b.minus;
	}
	return a.plus > b.plus;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<info>v(n);
	map<string, int>m;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].school >> v[i].teamname >> v[i].plus >> v[i].minus;
	}
	sort(v.begin(), v.end(), compare);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (m.find(v[i].school) == m.end())
		{
			cout << v[i].teamname << '\n';
			m.insert({ v[i].school, 0});
			count++;
		}
		if (count == k)
		{
			break;
		}
	}
	return 0;
}