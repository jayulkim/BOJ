#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		vector<int>v(n);
		for (auto& i : v)
		{
			cin >> i;
		}
		map<int, int>mm; // 값과 인덱스 저장
		vector<int>ans(n);
		bool flag = false;
		for (int i = 0; i < n; ++i)
		{
			if (flag)
			{
				break;
			}
			if (!v[i])
			{
				int pivot = 0;
				auto it = mm.lower_bound(1);
				if (it == mm.end())
				{
					pivot = n;
				}
				else
				{
					pivot = it->first - 1;
				}
				ans[i] = pivot;
			}
			else
			{
				if (mm.size() < v[i])
				{
					flag = true;
					break;
				}
				int cnt = 0, num = -1;
				vector<pii>remo;
				for (auto& [a, b] : mm)
				{
					if (remo.size() == v[i])
					{
						break;
					}
					pii pos = make_pair(a, b);
					if (pos.first - 1 <= 0)
					{
						flag = true;
						break;
					}
					remo.push_back(pos);
					cnt++;
					num = a;
				}
				for (auto& [a, b] : remo)
				{
					mm.erase(a);
					mm[a - 1] = b;
					ans[b]--;
				}
				ans[i] = num;
			}
			mm[ans[i]] = i;
		}
		if (flag)
		{
			cout << "IMPOSSIBLE" << '\n';
		}
		else
		{
			for (auto& i : ans)
			{
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}