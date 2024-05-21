#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;
	cin >> num;
	vector<pair<int, int>>v;
	while (num--)
	{
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int first = 0, second = 0;
			cin >> first >> second;
			v.push_back({ first, second });
		}
		sort(v.begin(), v.end());
		int Min = v[0].second;
		int count = 1;
		for (int i = 1; i < n; i++)
		{
			if (v[i].second < Min)
			{
				Min = v[i].second;
				count++;
			}
		}
		cout << count << '\n';
		v.clear();
	}
}