#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0;
vector<pair<ll, ll>>result;
vector<pair<ll, ll>>v;
int temp = -1;
bool visited[11];
ll Min = 987654321;
void dfs(int size) {
    if (result.size() == size) {
        ll a = 1, b = 0;
        for (auto& i : result) {
            a *= i.first;
            b += i.second;
        }
        Min = min(Min, llabs(a - b));
        return;
    }
    for (int i = temp + 1; i < v.size(); i++) {
        if (!visited[i]) {
            result.push_back({ v[i].first, v[i].second });
            visited[i] = true;
            dfs(size);
            visited[i] = false;
            result.pop_back();
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a = 0, b = 0;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    for (int i = 1; i <= n; i++) {
        dfs(i);
        temp = -1;
    }
    cout << Min;
    return 0;
}