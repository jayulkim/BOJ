#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
ll a[11];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<ll>v;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), greater<ll>());
    for (int i = 0; i < n; i++) {
        ll count = 0;
        for (int j = i; j >= 0; j--) {
            if (v[i] < v[j]) {
                count++;
            }
        }
        if (count < 4) {
            a[1]++;
        }
        else if (count < 11) {
            a[2]++;
        }
        else if (count < 23) {
            a[3]++;
        }
        else if (count < 40) {
            a[4]++;
        }
        else if (count < 60) {
            a[5]++;
        }
        else if (count < 77) {
            a[6]++;
        }
        else if (count < 89) {
            a[7]++;
        }
        else if (count < 96) {
            a[8]++;
        }
        else if (count >= 96) {
            a[9]++;
        }
    }
    for (int i = 1; i <= 9; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}