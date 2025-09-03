//사과 게임 탐색기
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
    cin >> n >> m >> k;
    if (m + 1 - k < 1) {
        cout << -1;
        return 0;
    }
    vector<ll>v;
    v.push_back(n - k + 1);
    for (int i = n - k; i >= m + 2 - k; i--) {
        v.push_back(i);
    }
    for (int i = 1; i <= m + 1 - k; i++) {
        v.push_back(i);
    }
    for (int i = n - k + 2; i <= n; i++) {
        v.push_back(i);
    }
    vector<bool>visited(n + 1, false);
    for (auto& i : v) {
        if (visited[i]) {
            cout << -1;
            return 0;
        }
        visited[i] = true;
    }
    for (auto& i : v) {
        cout << i << ' ';
    }
    return 0;
}