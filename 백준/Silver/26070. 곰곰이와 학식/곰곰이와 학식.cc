#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ary[3];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    ary[0] = d - a;
    ary[1] = e - b;
    ary[2] = f - c;
    ll result = a + b + c;
    for (int i = 0; i < 3; i++) {
        if (ary[i] >= 3) {
            ary[(i + 1) % 3] += (ary[i] / 3);
            ary[i] %= 3;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (ary[i] >= 3) {
            ary[(i + 1) % 3] += (ary[i] / 3);
            ary[i] %= 3;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (ary[i] >= 3) {
            ary[(i + 1) % 3] += (ary[i] / 3);
            ary[i] %= 3;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (ary[i] < 0) {
            result += ary[i];
        }
    }
    cout << result;
    return 0;
}