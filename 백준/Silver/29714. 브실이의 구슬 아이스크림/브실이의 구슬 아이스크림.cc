#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
map<ll, ll>Map;
int main(void) {
	ios::sync_with_stdio(false);	
    cin.tie(0);
	cin >> n;
    for (int j = 0; j < n; j++) {
        ll num = 0;
        cin >> num;
        Map[num]++;
    }
    cin >> m;
    for (int j = 0; j < m; j++) {
        ll num = 0;
        cin >> num;
        map<ll, ll>v;
        bool find = false;
        for (int k = 0; k < num; k++) {
            ll a = 0;
            cin >> a;
            v[a]++;
            if (v[a] > Map[a]) {
                find = true;
            }
        }
        if (!find) {
            for (auto iter = v.begin(); iter != v.end(); iter++) {
                Map[iter->first] -= iter->second;
            }
        }
        cin >> num;
        for (int j = 0; j < num; j++) {
            ll a = 0;
            cin >> a;
            if (!find) {
                Map[a]++;
            }
        }
        map<ll, ll>().swap(v);
    }
    ll count = 0;
    for (auto iter = Map.begin(); iter != Map.end(); iter++) {
        for (int j = 0; j < iter->second; j++) {
            count++;
        }
    }
    cout << count << '\n';
    for (auto iter = Map.begin(); iter != Map.end(); iter++) {
        for (int j = 0; j < iter->second; j++) {
            cout << iter->first << ' ';
        }
    }
	return 0;
}