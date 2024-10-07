#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b) {
    int temp = a % b;
    while (temp > 0) {
        a = b;
        b = temp;
        temp = a % b;
    }
    return b;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n = 0, m = 0;
    cin >> n;
    vector<ll>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> m;
    double sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (gcd(m, v[i]) == 1) {
            sum += v[i];
            count++;
        }
    }
    cout.precision(30);
    cout << fixed;
    cout << sum / count;
    return 0;
}