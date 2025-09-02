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
    cin >> n >> m;
    vector<ll>vv;
    vector<vector<ll>>sum(21, vector<ll>(n + 1, 0));
    vector<vector<ll>>v(21, vector<ll>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        string str = "";
        cin >> str;
        v[str.length()][i]++;
        vv.push_back(str.length());
    }
    for (int i = 1; i <= 20; i++) {
        sum[i][0] = v[i][0];
        for (int j = 1; j < n; j++) {
            sum[i][j] = sum[i][j - 1] + v[i][j];
        }
    }
    ll result = 0;
    m = min(m, n - 1);
    for (int i = m; i >= 1; i--) {
        result += sum[vv[i]][i - 1];
    }
    for (int i = 1; i <= n - m - 1; i++) {
        result += sum[vv[i + m]][m + i - 1] - sum[vv[i + m]][i - 1];
    }
    cout << result;
    return 0;
}