#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0, k = 0;
vector<ll>result;
ll Count = 0;
void dfs() {
    if (result.size() == n) {
        if (result[0] != 0) {
            ll sum = 0;
            for (auto& i : result) {
                sum += i;
            }
            if (sum % 3 == 0) {
                Count++;
            }
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        result.push_back(i);
        dfs();
        result.pop_back();
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dfs();
    cout << Count;
    return 0;
}