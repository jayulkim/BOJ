#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ary[501];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ary[1] = 1;
    for (int i = 2; i <= 50; i++) {
        ary[i] = ary[i - 1] + ary[i - 2];
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        vector<ll>v;
        while (n > 0) {
            for (int i = 50; i >= 0; i--) {
                if (ary[i] <= n) {
                    n -= ary[i];
                    v.push_back(ary[i]);
                    break;
                }
            }
        }
        sort(v.begin(), v.end());
        for (auto& i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}