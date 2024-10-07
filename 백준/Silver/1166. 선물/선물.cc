#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int ll;
int main(void)
{
	ld n = 0, l = 0, w = 0, h = 0;
	cin >> n >> l >> w >> h;
	ld start = 0;
	ld end = min(min(l, w), h);
	ld mid = 0;
	while (start < end - 0.000000001)
	{
		mid = (start + end) / 2;
		if ((ll)n <= ((ll)(l / mid) *(ll)(w / mid) * (ll)(h / mid)))
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
	}
	cout.precision(30);
	cout << mid;
	return 0;
}