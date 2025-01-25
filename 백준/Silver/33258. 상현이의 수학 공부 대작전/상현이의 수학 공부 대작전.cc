#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
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
    cin >> m;
    ll start = 1, end = 1e9, mid = 0;
    ll Min = LLONG_MAX;
    while (start <= end) {
        mid = (start + end) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mid >= v[i]) {
                sum += mid;
            }
            else {
                sum += 2 * (mid - v[i]);
            }
        }
        if (sum >= m) {
            Min = min(Min, mid);
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    cout << Min;
    return 0;
}