#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll>tp;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int  T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0, m = 0;
		cin >> n;
		int ed = INT_MIN;
		map<int, set<int>>mm;
		vector<pll>query;
		for (int i = 0; i < n; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			ed = max(ed, a);
			mm[a].insert(b);
		}
		vector<tp>ans;
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			int temp = 0;
			cin >> temp;
			query.push_back(make_pair(temp, i));
		}
		sort(query.begin(), query.end());
		int pre = 0;
		int cnt = 1, idx = 0;
		for (int i = 0; i <= ed; ++i)
		{
			if (mm[i].find(pre) == mm[i].begin())
			{
				for (auto it = mm[i].begin(); it != mm[i].end(); ++it)
				{
					if (idx < m && cnt == query[idx].first)
					{
						while (idx < m && cnt == query[idx].first)
						{
							ans.push_back(make_tuple(query[idx].second, i, *it));
							idx++;
						}
					}
					pre = *it;
					cnt++;
				}
			}
			else
			{
				for (auto it = prev(mm[i].end());; --it)
				{
					if (idx < m && cnt == query[idx].first)
					{
						while (idx < m && cnt == query[idx].first)
						{
							ans.push_back(make_tuple(query[idx].second, i, *it));
							idx++;
						}
					}
					pre = *it;
					cnt++;
					if (it == mm[i].begin())
					{
						break;
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		for (auto& [_, a, b] : ans)
		{
			cout << a << ' ' << b << '\n';
		}
	}
	return 0;
}