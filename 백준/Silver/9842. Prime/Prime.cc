#include <bits/stdc++.h>
using namespace std;
bool ary[150001];
vector<int>v;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i * i <= 150000; i++) {
        if (!ary[i]) {
            for (int j = i * i; j <= 150000; j += i) {
                ary[j] = true;
            }
        }
    }
    for (int i = 2; i <= 150000; i++) {
        if (!ary[i]) {
            v.push_back(i);
        }
    }
    int n = 0;
    cin >> n;
    cout << v[n - 1];
    return 0;
}