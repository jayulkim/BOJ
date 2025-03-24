// 폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(0);
    ll a = 0, b = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        a += num;
    }
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        b += num;
    }
    cout << b << ' ' << a;
	return 0;
}    