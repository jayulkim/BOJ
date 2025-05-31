#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<bool>visited(10001, false);
    for (int i = 1; i <= 100; i++) {
        visited[i * i] = true;
    }
    ll result = 0;
    ll Min = LLONG_MAX;
    for (int i = n; i <= m; i++) {
        if (visited[i]) {
            result += i;
            Min = min(Min, (ll)i);
        }
    }
    if (!result) {
        cout << -1;
        return 0;
    }
    cout << result << '\n';
    cout << Min;
    return 0;
}