//폰 코딩
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
    cin >> n;
    vector<vector<ll>>v(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            ll num = 0;
            cin >> num;
            v[i].push_back(num);
        }
        sort(v[i].begin(), v[i].end());
    }
    pll result = {0, 0};
    for (int i = 0; i < n; i++) {
        ll Max = 0;
        do {
            ll temp = 0;
            for (int j = 0; j < 3; j++) {
                temp += v[i][j];
            }
            Max = max(Max, temp % 10);
        } while (next_permutation(v[i].begin(), v[i].end()));
        result = max(result, {Max, i});
    }
    cout << result.second + 1;
    return 0;
}