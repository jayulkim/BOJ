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
    cin >> n >> m;
    ll size = m;
    vector<pll>v;
    for (int i = 0; i < n; i++) {
        ld a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        v.push_back({ (ll)ceil(sqrt(a * a + b * b)), c });
    }
    sort(v.begin(), v.end(), greater<pll>());
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    ll idx = 0;
    ll vidx = 0;
    vector<vector<ll>>vv(n + 1);
    while (idx < n && v[idx].first > m) {
        idx++;
    }
    vector<ll>vvv(n + 1, 0);
    while (idx < n && m) {
        ll finddist = -1;
        vvv[vidx] = size - v[idx].first + 1;
        while (idx < n && m >= v[idx].first && v[idx].first > m - 1) {
            if (finddist == -1) {
                finddist = v[idx].first;
            }
            vv[vidx].push_back(v[idx++].second);
        }
        if (finddist == -1) {
            if (idx < n) {
                m = v[idx].first;
            }
            else {
                break;
            }
        }
        else {
            m--;
            vidx++;
        }
    }
    for (int i = 0; i < vidx; i++) {
        for (auto& j : vv[i]) {
            if (pq.size() < vvv[i]) {
                pq.push(j);
            }
            else if (pq.top() < j) {
                pq.pop();
                pq.push(j);
            }
        }
    }
    ll result = 0;
    while (!pq.empty()) {
        ll temp = pq.top();
        pq.pop();
        result += temp;
    }
    cout << result;
    return 0;
}