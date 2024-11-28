#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
ll n = 0, m = 0, k = 0;
bool visited[11][11];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<pll>v;
	ll cnt = 0;
	while (cnt < 4) {
		if (!visited[((n + (n / 13) + 15) / 10) % 10][(n + (n / 13) + 15) % 10]) {
			visited[((n + (n / 13) + 15) / 10) % 10][(n + (n / 13) + 15) % 10] = true;
			v.push_back({ ((n + (n / 13) + 15) / 10) % 10, (n + (n / 13) + 15) % 10 });
			cnt++;
		}	
		n = (n + (n / 13) + 15);
	}
	string str = "";
	ll count = 4;
	ll result = 0;
	while (count) {
		cin >> str;
		ll x = (str[0] - '0');
		ll y = (str[1] - '0');
		if (visited[x][y]) {
			cout << "You hit a wumpus!" << '\n';
			visited[x][y] = false;
			count--;
			if (count) {
				ll Min = LLONG_MAX;
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (visited[i][j]) {
							Min = min(Min, llabs(x - i) + llabs(y - j));
						}
					}
				}
				cout << Min << '\n';
			}
		}
		else {
			if (count) {
				ll Min = LLONG_MAX;
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (visited[i][j]) {
							Min = min(Min, llabs(x - i) + llabs(y - j));
						}
					}
				}
				cout << Min << '\n';
			}
		}
		result++;
	}
	cout << "Your score is " << result << " moves.";
    return 0;
}