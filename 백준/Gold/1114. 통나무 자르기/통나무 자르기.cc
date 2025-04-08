#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ll, ll, ll, ll> llll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<ll>v;
    for (int i = 0; i < m; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
    }
    v.push_back(0);
    v.push_back(n);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<ll>vv;
    for (int i = 0; i < v.size() - 1; i++) {
        vv.push_back(v[i + 1] - v[i]);
    }
    sort(v.begin(), v.end());
    ll start = 1, end = n, mid = 0;
    pll Min = { LLONG_MAX, LLONG_MAX };
    while (start <= end) {
        mid = (start + end) / 2;
        bool find = false;
        ll sum = 0;
        ll sumsum = 0;
        ll count = k;
        ll idx = LLONG_MAX;
        for (int i = vv.size() - 1; i >= 0; i--) {
            if (vv[i] > mid) {
                find = true;
                break;
            }
            if (sum + vv[i] > mid) {
                if (count) {
                    count--;
                    idx = min(idx, n - sumsum);
                    sum = 0;
                }
                else {
                    find = true;
                    break;
                }
            }
            sum += vv[i];
            sumsum += vv[i];
        }
        if (count) {
            idx = v[1];
        }
        sum = 0;
        sumsum = 0;
        count = k;
        for (int i = 0; i < vv.size(); i++) {
            if (vv[i] > mid) {
                find = true;
                break;
            }
            if (sum + vv[i] > mid) {
                if (count) {
                    count--;
                    idx = min(idx, sumsum);
                    sum = 0;
                }
                else {
                    find = true;
                    break;
                }
            }
            sum += vv[i];
            sumsum += vv[i];
        }
        if (count) {
            idx = v[1];
        }
        if (!find) {
            end = mid - 1;
            Min = min(Min, { mid, idx });
        }
        else {
            start = mid + 1;
        }
    }
    cout << Min.first << ' ' << Min.second;
    return 0;
}