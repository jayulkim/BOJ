//폰 코딩
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> lll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;
map<lll, ll>v;
ll parent[1001];
ll getparent(ll x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = getparent(parent[x]);
}
void merge(ll a, ll b) {
    a = getparent(a);
    b = getparent(b);
    if (a > b) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
    }
}
ll kruskal(ll n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    ll result = 0;
    ll count = 0;
    priority_queue<lll, vector<lll>, greater<lll>>pq;
    vector<lll>vv;
    for (auto& i : v) {
        auto [a, b, c] = i.first;
        pq.push({a, b, c});
    }
    while (!pq.empty() && count < n - 1) {
        auto [a, b, c] = pq.top();
        pq.pop();
        if (getparent(b) != getparent(c)) {
            merge(b, c);
            result += a;
            count++;
            vv.push_back({a, b, c});
        }
    }
    if (count < n - 1) {
        return 0;
    }
    sort(vv.begin(), vv.end());
    auto [a, b, c] = vv[0];
    v.erase(v.find({a, b, c}));
    return result;
}
int main(void) {
	ios::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v[{i + 1, a, b}]++;
    }
    vector<ll>result;
    for (int i = 0; i < k; i++) {
        result.push_back(kruskal(n));
    }
    for (auto& i : result) {
        cout << i << ' ';
    }
	return 0;
}