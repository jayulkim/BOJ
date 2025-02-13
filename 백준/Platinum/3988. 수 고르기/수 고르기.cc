#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<ll>v;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
    }
    priority_queue<tp, vector<tp>, greater<tp>>pq;
    sort(v.begin(), v.end());
    ll start = 0, end = n - 1 - m;
    for (int i = start; i <= end - 1; i++) {
        pq.push({ v[i + 1] - v[i], i, i + 1 });
    }
    ll Min = LLONG_MAX;
    while (1) {
        Min = min(Min, v[end] - v[start] + get<0>(pq.top()));
        start++;
        end++;
        if (end >= n) {
            break;
        }
        while (!pq.empty() && get<2>(pq.top()) < start) {
            pq.pop();
        }
        pq.push({ v[end] - v[end - 1], end - 1, end });
    }
    cout << Min;
    return 0; 
}