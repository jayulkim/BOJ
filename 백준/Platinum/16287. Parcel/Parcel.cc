#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int w = 0, n = 0;
	cin >> w >> n;
	vector<int>v(n);
	for (auto& i : v)
	{
		cin >> i;
	}
	sort(v.begin(), v.end());
	vector<int>left(800000, false);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			left[v[i] + v[j]] = true;
		}
		for (int j = i + 2; j < n; ++j)
		{
			int pivot = v[i + 1] + v[j];
			if (pivot < w)
			{
				if (left[w - pivot])
				{
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO";
	return 0;
}