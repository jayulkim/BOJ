#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n = 0;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		v[i] = a - b;
	}
	sort(v.begin(), v.end());
	if (n % 2 == 0)
	{
		cout << v[n / 2] - v[n / 2 - 1] + 1;
	}
	else
	{
		cout << 1;
	}
	return 0;
}