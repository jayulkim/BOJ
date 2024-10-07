#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct info
{
	int index;
	ll number;
};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	vector<info>v;
	vector<info>st;
	vector<ll>ary;
	while (num--)
	{
		int n = 0;
		cin >> n;
		v.resize(n);
		ary.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i].number;
			v[i].index = i;
		}
		ll result = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (st.empty())
			{
				st.push_back(v[i]);
				ary[i] = i;
			}
			else
			{
				while (!st.empty() && st.back().number < v[i].number)
				{
					st.pop_back();
				}
				if (st.empty())
				{
					ary[i] = v[i].index;
					st.push_back(v[i]);
				}
				else
				{
					ary[i] = st.back().index;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			result += (v[ary[i]].number - v[i].number);
		}
		cout << result << '\n';
		st.clear();
		ary.clear();
	}
}