#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<int>m(n);
	for (auto& i : v)
	{
		m.push_back(i * n--);
	}
	sort(m.begin(), m.end());
	cout << m.back();
}