#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, m = 0;
    cin >> n >> m;
    if (n <= 1023) {
        cout << "No thanks";
    }
    else {
        n -= 1023;
        for (int i = 0; i < 11; i++) {
            if ((n & (1 << i)) && !(m & (1 << i))) {
                cout << "Impossible";
                return 0;
            }
        }
        cout << "Thanks";
    }
    return 0;
}