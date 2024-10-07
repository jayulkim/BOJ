#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	cin >> n;
	vector<int>v(2, 0);
	vector<int>a = { 100,50,20,10,5,2,1 };
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		if (v[0] > v[1])
		{
			v[1] += temp;
		}
		else
		{
			v[0] += temp;
		}
	}
	int pivot = abs(v[1] - v[0]);
	for (auto& i : a)
	{
		ans += pivot / i;
		pivot %= i;
	}
	cout << ans;
	return 0;
}