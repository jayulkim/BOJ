#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll> lll;
typedef tuple<pll, string, ll> pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> m;
    vector<lll>v;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    ll start = 1, end = 1e18, mid = 0;
    ll Min = LLONG_MAX;
    while (start <= end) { 
        mid = (start + end) / 2;
        ll temp = mid;
        bool find = false;
        ll at = m;
        for (auto& [a, b, c] : v) {
            if (a == 1) {
                if (c % at) {
                    temp -= b * (c / at);
                }
                else {
                    temp -= b * (c / at - 1);
                }
                if (temp <= 0) {
                     find = true;
                     break;
                }
            }
            else {
                at += b;
                temp = min(mid, temp + c);
            }
        }
        if (!find) {
            Min = min(Min, mid);
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    cout << Min;
	return 0;
}