#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> tp;
ll n = 0, m = 0, k = 0;
bool compare(const tp& a, const tp& b) {
    if (get<1>(a) * get<2>(b) == get<1>(b) * get<2>(a) && get<2>(a) == get<2>(b)) {
        return get<0>(a) < get<0>(b);
    }
    else if (get<1>(a) * get<2>(b) == get<1>(b) * get<2>(a)) {
        return get<2>(a) < get<2>(b);
    }
    return get<1>(a) * get<2>(b) > get<1>(b) * get<2>(a);
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<tp>v;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        v.push_back({ a, c, b });
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < m; i++) {
        cout << get<0>(v[i]) << '\n';
    }
    return 0;
}