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
    ll sum = 0;
    priority_queue<lll, vector<lll>, greater<lll>>pq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (islower(c)) {
                sum += c - 'a' + 1;
                pq.push({c - 'a' + 1, i, j});
            }
            else if (isupper(c)) {
                sum += c - 'A' + 27;
                pq.push({c - 'A' + 27, i, j});
            }
        }
    }
    vector<ll>parent(n + 1);
    vector<ll>rank(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    function<ll(ll)> getparent = [&](ll x) -> ll {
        if (x == parent[x]) {
            return x;
        }        
        return parent[x] = getparent(parent[x]);
        };
    function<void(ll, ll)> merge = [&](ll a, ll b) -> void {
        a = getparent(a);
        b = getparent(b);
        if (rank[a] < rank[b]) {
            parent[a] = b;
        }
        else {
            parent[b] = a;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
        };
    ll count = 0;
    ll result = 0;
    while (!pq.empty() && count < n - 1) {
        auto [a, b, c] = pq.top();
        pq.pop();
        if (getparent(b) != getparent(c)) {
            result += a;
            merge(b, c);
            count++;
        }
    }
    if (count != n - 1) {
        cout << -1;
        return 0;
    }
    cout << sum - result;
    return 0;
}