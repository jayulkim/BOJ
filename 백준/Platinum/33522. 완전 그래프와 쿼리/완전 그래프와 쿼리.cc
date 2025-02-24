#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, string> pls;
typedef pair<string, ll> psl;
typedef tuple<ll, ll, ll>tp;
typedef tuple<pll, string, ll>pllsl;
ll n = 0, m = 0, k = 0;
bool visited[100001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i * i <= 100000; i++) {
        if (!visited[i]) {
            for (int j = i * i; j <= 100000; j += i) {
                visited[j] = true;
            }
        }
    }
    cin >> n;
    vector<pll>result;
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            result.push_back({ 1, i });  
            if (visited[i]) {
                result.push_back({ 2, i });
            }
        }
        else if (i != 2) {
            result.push_back({ 2, i });
        }
    }
    cout << result.size() << '\n';
    for (auto& i : result) {
        cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}