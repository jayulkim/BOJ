#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
ll n = 0, m = 0, k = 0;
vector<ll>parent(3001);
bool check(tp a, tp b) {
    if ((get<0>(a) - get<0>(b)) * (get<0>(a) - get<0>(b)) + (get<1>(a) - get<1>(b)) * (get<1>(a) - get<1>(b)) <= (get<2>(a) + get<2>(b)) * (get<2>(a) + get<2>(b))) {
        return true;
    }
    return false;
}
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
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll num = 0;
    cin >> num;
    while (num--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        vector<tp>v;
        for (int i = 0; i < n; i++) {
            ll x = 0, y = 0, r = 0;
            cin >> x >> y >> r;
            v.push_back({ x, y, r });
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(v[i], v[j])) {
                    if (getparent(i) != getparent(j)) {
                        merge(i, j);
                    }
                }
            }
        }
        map<ll, ll>Map;
        for (int i = 0; i < n; i++) {
            parent[i] = getparent(i);
            Map[parent[i]]++;
        }
        cout << Map.size() << '\n';
    }
    return 0;
}