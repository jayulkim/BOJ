#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<pll>aa;
    vector<pll>bb;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0, c = 0, d = 0;
        cin >> a >> b >> c >> d;
        if (d) {
            if (c) {
                bb.push_back({a, 0});
            }
            else {
                bb.push_back({a, b});
            }
        }
        else {
            if (c) {
                aa.push_back({a, 0});
            }
            else {
                aa.push_back({a, b});
            }
        }
    }
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    ll result = 0;
    ll count = 0;
    ll idxa = 0, idxb = 0;
    ll a = 0, b = 0;
    cin >> a >> b;
    while (count < m) {
        while (idxa < aa.size() && a >= aa[idxa].first) {
            pq.push(aa[idxa].second);
            idxa++;
        }
        while (idxb < bb.size() && a * 2 >= bb[idxb].first) {
            pq.push(bb[idxb].second / 2);
            idxb++;
        }
        if (!pq.empty()) {
            ll temp = pq.top();
            pq.pop();
            result += max((ll)0, temp - b);
            count++;
            a++;
            b++;
        }
        else {
            break;
        }
    }
    if (count < m) {
        cout << -1;
        return 0;
    }
    cout << result;
    return 0;
}