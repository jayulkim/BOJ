#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<ll>v;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    ll result = 0;
    if (n % 2) {
        result = v.back();
        for (int i = 0; i < n - 1; i++) {
            result = max(result, v[i] + v[n - i - 2]);
        }
        cout << result;
    }
    else {
        for (int i = 0; i < n; i++) {
            result = max(result, v[i] + v[n - i - 1]);
        }
        cout << result;
    }
    return 0;
}