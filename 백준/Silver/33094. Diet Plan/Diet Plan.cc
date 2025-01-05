#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<ll>v;
    for (int j = 0; j < n; j++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
    }
    priority_queue<ll>pq;
    ll sum = 0;
    for (int j = 0; j < n; j++) {
        pq.push(v[j]);
        sum += v[j];
        if (sum > m) {
            while (sum > m && k && !pq.empty()) {
                sum -= pq.top();
                pq.pop();
                k--;
            }
            if (sum > m) {
                cout << j;
                return 0;
            }
        }
    }
    cout << n;
}