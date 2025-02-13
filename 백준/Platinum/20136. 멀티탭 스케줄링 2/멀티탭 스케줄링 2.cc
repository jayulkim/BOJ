#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
priority_queue<ll, vector<ll>, greater<ll>>pq[500001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    if (n >= m) {
        cout << 0;
        return 0;
    }
    vector<ll>v;
    for (int i = 0; i < m; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
        pq[num].push(i);
    }
    ll count = 0;
    map<ll, ll>Map;
    priority_queue<pll>temp;
    for (int i = 0; i < m; i++) {
        if (Map.size() < n) {
            if (!Map[v[i]]) {
                Map[v[i]]++;
            }
        }
        else {
            if (!Map[v[i]]) {
                pll a = temp.top();
                temp.pop();
                count++;
                Map[a.second] = 0;
                Map[v[i]]++;
            }
        }
        pq[v[i]].pop();
        if (!pq[v[i]].empty()) {
            temp.push({ pq[v[i]].top(), v[i] });
        }
        else {
            temp.push({ LLONG_MAX, v[i] });
        }
    }
    cout << count;
    return 0;
}