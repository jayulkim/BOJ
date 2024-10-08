#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ary[1001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ary[0] = true;
    ary[1] = true;
    for (int j = 2; j * j <= 1000; j++) {
        for (int k = j * j; k <= 1000; k += j) {
            if (!ary[k]) {
                ary[k] = true;
            }
        }
    }
    ll num = 0;
    cin >> num;
    while (num--) {
        ll n = 0;
        cin >> n;
        vector<ll>v;
        bool find = false;
        for (int j = 2; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                if (!ary[j] && !ary[k] && !ary[n - j - k] && j >= 2 && k >= 2 && n - j - k >= 2) {
                    v.push_back(j);
                    v.push_back(k);
                    v.push_back(n - j - k);
                    find = true;
                    break;
                }
            }
            if (find) {
                break;
            }
        }
        if (!find) {
            cout << 0;
        }
        else {
            sort(v.begin(), v.end());
            for (auto& j : v) {
                cout << j << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}