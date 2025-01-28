#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> m >> k;
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    for (int i = 0; i < m; i++) {
        ll num = 0;
        cin >> num;
        pq.push(num);
        sum += num;
    }
    while (!pq.empty() && sum - pq.top() >= n) {
        sum -= pq.top();
        pq.pop();
    }
    if (sum < n) {
        cout << -1 << '\n';
    }
    else {
        cout << pq.size() << '\n';
    }
    for (int i = 0; i < k; i++) {
        ll num = 0;
        cin >> num;
        pq.push(num);
        sum += num;
        while (!pq.empty() && sum - pq.top() >= n) {
            sum -= pq.top();
            pq.pop();
        }
        if (sum < n) {
            cout << -1 << '\n';
        }
        else {
            cout << pq.size() << '\n';
        }
    }
    return 0;
}