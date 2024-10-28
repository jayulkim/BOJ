#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll>dp(1000001, 987654321);
    cin >> n;
    vector<ll>v;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        dp[num] = 1;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cin >> m;
   
    for (int i = 1; i <= v.back() * m; i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i - v[j] > 0) {
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }
    for (int i = 1; i <= v.back() * m; i++) {
        if (dp[i] > m) {
            if (i % 2) {
                cout << "jjaksoon win at " << i;
                break;
            }
            else {
                cout << "holsoon win at " << i;
                break;
            }
        }
    }
    return 0;
}