#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<ll>prefix(1, 0);
	for (int i = 0;; ++i)
	{
		ll pivot = prefix.back() + (1LL << i);
		if (pivot < 0)
		{
			break;
		}
		prefix.push_back(pivot);
	}
	ll n = 0;
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	int cnt = 1, idx = 2;
	while (1)
	{
		ll sum = prefix[idx] - prefix[0];
		if (n <= cnt + (cnt + 1) * sum)
		{
			cout << cnt;
			return 0;
		}
		cnt++, idx++;
	}
	return 0;
}