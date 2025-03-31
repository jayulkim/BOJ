//폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 4; i++) {
        ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        pll aleftdown = { a, b };
        pll arightup = { c, d };
        pll bleftdown = { e, f };
        pll brightup = { g, h };
        if (aleftdown > arightup) {
            swap(aleftdown, arightup);
        }
        if (bleftdown > brightup) {
            swap(bleftdown, brightup);
        }
        if (aleftdown > bleftdown) {
            swap(aleftdown, bleftdown);
            swap(arightup, brightup);
        }
        if (arightup.first < bleftdown.first || arightup.second < bleftdown.second || aleftdown.second > brightup.second) {
            cout << "d" << '\n';
        }
        else if (arightup == bleftdown || (aleftdown.second == brightup.second && arightup.first == bleftdown.first)) {
            cout << "c" << '\n';
        }
        else if (arightup.first == bleftdown.first || arightup.second == bleftdown.second || aleftdown.second == brightup.second) {
            cout << "b" << '\n';
        }
        else {
            cout << "a" << '\n';
        }
    }
    return 0;
}