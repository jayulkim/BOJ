#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    ll temp = a % b;
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
    int num = 0;
    cin >> num;
    while (num--) {
        ll a = 0, b = 0;
        cin >> a >> b;
        cout << a * b / gcd(a, b) << '\n';
    }
    return 0;
}