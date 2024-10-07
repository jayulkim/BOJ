#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, ll>Map;
map<string, ll>wMap;
map<string, ll>dMap;
bool day[11][7];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name = "";
		ll w = 0, d = 0, cost = 0;
		cin >> name >> w >> d >> cost;
		Map[name] = cost;
		wMap[name] = w;
		dMap[name] = d;
	}
	for (int i = 0; i < n; i++) {
		string name = "";
		ll cost = 0;
		cin >> name >> cost;
		if (cost >= Map[name]) {
			day[wMap[name]][dMap[name]] = true;
		}
	}
	ll count = 0, Max = 0;
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 6; j++) {
			if (day[i][j]) {
				count++;
			}
			else {
				count = 0;
			}
			Max = max(Max, count);
		}
	}
	cout << Max;
	return 0;
}