#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, m = 0;
    cin >> n >> m;
    vector<ll>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<ll>ary;
    for (int i = 0; i < v.size() - 1; i++) {
        ary.push_back(v[i + 1] - v[i]);
    }
    ary.push_back(v[0]);
    sort(ary.begin(), ary.end());
    ll result = 0;
    for (int i = 0; i < ary.size() - m; i++) {
        result += ary[i];
    }
    cout << result;
    return 0;
}