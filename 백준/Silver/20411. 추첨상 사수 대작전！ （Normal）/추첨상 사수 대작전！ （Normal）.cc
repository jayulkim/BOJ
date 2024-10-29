#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0, h = 0;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> h;
    for (int i = 0; i < n; i++) {
        if (((m - k) * i + h - k) % n == 0) {
            for (int j = 0; j < n; j++) {
                if ((k + h) % n == (i * (m + k) + 2 * j) % n) {
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}