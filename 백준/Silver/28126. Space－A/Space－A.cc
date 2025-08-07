#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string str = "";
    cin >> str;
    ll a = 0, b = 0, c = 0;
    for (auto& i : str) {
        if (i == 'U') {
            b++;
        }
        else if (i == 'R') {
            a++;
        }
        else {
            c++;
        }
    }
    cin >> m;
    ll result = 0;
    for (int i = 0; i < m; i++) {
        ll aa = 0, bb = 0;
        cin >> aa >> bb;
        aa--;
        bb--;
        ll temp = min({ aa, bb, c });
        if (aa - temp <= a && bb - temp <= b) {
            result++;
        }
    }
    cout << result;
    return 0;
}