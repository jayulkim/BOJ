#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare(const ll& num1, const ll& num2)
{
	return num1 < num2;
}
int main(void)
{
	int n = 0;
	ll me = 0;
	cin >> n >> me;
	vector<ll>v(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n - 1; i++)
	{
		if (me <= v[i])
		{
			cout << "No";
			return 0;
		}
		else
		{
			me += v[i];
		}
	}
	cout << "Yes";
	return 0;
}