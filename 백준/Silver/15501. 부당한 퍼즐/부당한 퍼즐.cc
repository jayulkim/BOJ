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
    for (int i = 0; i < n; i++) {
        cin >> m;
        v.push_back(m);
    }
    ll idx = 0;
    vector<ll>vv;
    for (int i = 0; i < n; i++) {
        cin >> m;
        vv.push_back(m);
        if (m == v[0]) {
            idx = i;
        }
    }
    if (n == 1) {
        if (v == vv) {
            cout << "good puzzle";
        }
        else {
            cout << "bad puzzle";
        }
    }
    else {
        ll forward = 0;
        if (vv[(idx - 1 + n) % n] == v[1]) {
            forward = -1;
        }
        else if (vv[(idx + 1) % n] == v[1]) {
            forward = 1;
        }
        else {
            cout << "bad puzzle";
            return 0;
        }
        queue<ll>q;
        q.push(idx);
        ll i = 0;
        while (!q.empty() && i < n) {
            ll temp = q.front();
            q.pop();
            if (vv[temp] != v[i]) {
                cout << "bad puzzle";
                return 0;
            }
            else {
                i++;
                q.push((temp + forward + n) % n);
            }
        }
        cout << "good puzzle";
    }
    return 0; 
}