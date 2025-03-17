#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<ll, ll>Map;
char MapMap[10][10];
ll getnum(ll y, ll x, ll yd, ll xd) {
    ll Max = -1;
    string result = "";
    ll dy = y;
    ll dx = x;
    while (1) {
        result += MapMap[dy][dx];
        dy += yd;
        dx += xd;
        if (Map[stoll(result)]) {    
            Max = max(Max, stoll(result));
        }
        if (dy < 0 || dy >= n || dx < 0 || dx >= m) {
            break;
        }
    }
    return Max;
}
int main(void) {
	ios::sync_with_stdio(false);	
    cin.tie(0);
    Map[0]++;
	ll temp = 1;
    while (temp * temp <= 999999999) {
        Map[temp * temp]++;
        temp++;
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> MapMap[i][j];
        }
    }
    ll Max = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int u = -max(n, m); u <= max(n, m); u++) {
                for (int h = -max(n, m); h <= max(n, m); h++) {
                    if (!(!u && !h)) {
                        Max = max(Max, getnum(i, j, u, h));
                    }
                }
            }
        }
    }
    cout << Max;
	return 0;
}    