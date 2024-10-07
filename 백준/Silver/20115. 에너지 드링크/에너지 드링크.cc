#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
int main(void) {
	ios::sync_with_stdio(false);	
    cin.tie(0);
	ll n = 0;
    cin >> n;
    vector<ll>v(n);
    for (int j = 0; j < n; j++) {
        cin >> v[j];
    }
    sort(v.begin(), v.end());
    ll Max = v[n - 1];
    for (int j = 0; j < n - 1; j++) {
        Max += (v[j] / 2);
    }
    cout << Max;
	return 0;
}