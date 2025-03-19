#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, k = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if (n == 3) {
       cout << -1; 
    }
    else if (n % 2) {
        cout << 2 << '\n';
        cout << 1 << '\n';
        for (int i = 3; i <= n - 1; i++) {
            cout << i + 1 << '\n';
        }
        cout << 3;
    }
    else if (n % 2 == 0) {
        cout << 2 << '\n';
        for (int i = 2; i <= n - 2; i++) {
            cout << i + 2 << '\n';
        }
        cout << 1 << '\n';
        cout << 3;
    }
    return 0;
}