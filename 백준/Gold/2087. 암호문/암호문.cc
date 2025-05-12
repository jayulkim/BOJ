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
    vector<ll>v;
    for (int i = 0; i < n / 2; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
    }
    vector<ll>vv;
    for (int i = n / 2; i < n; i++) {   
        ll num = 0;
        cin >> num;
        vv.push_back(num);
    }
    cin >> m;
    ll a = pow(2, v.size());
    ll b = pow(2, vv.size());
    unordered_map<ll, ll>aMap;
    for (int i = 1; i <= a; i++) {
        ll temp = i;
        ll sum = 0;
        for (int j = 0; j < v.size(); j++) {
            if (temp & (1 << j)) {
                sum += v[j];
            }
        }
        aMap[sum] = i;
    }
    unordered_map<ll, ll>bMap;
    for (int i = 1; i <= b; i++) {
        ll temp = i;
        ll sum = 0;
        for (int j = 0; j < vv.size(); j++) {
            if (temp & (1 << j)) {
                sum += vv[j];
            }
        }
        bMap[sum] = i;
    }
    vector<ll>result(n + 1, 0);
    for (auto& i : aMap) {
        if (bMap[m - i.first]) {
            for (int j = 0; j < v.size(); j++) {
                if (i.second & (1 << j)) {
                    result[j] = 1;
                }
            }
            for (int j = 0; j < vv.size(); j++) {
                if (bMap[m - i.first] & (1 << j)) {
                    result[j + n / 2] = 1;
                }
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << result[i];
    }
    return 0;
}