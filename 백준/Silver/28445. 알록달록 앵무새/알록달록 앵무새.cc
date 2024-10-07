#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string>result;
vector<string>v;
void dfs() {
    if (result.size() == 2) {
        cout << result[0] << ' ' << result[1] << '\n';
        return;
    }
    string temp = "";
    for (int i = 0; i < v.size(); i++) {
        if (temp != v[i]) {
            result.push_back(v[i]);
            temp = v[i];
            dfs();
            result.pop_back();
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a = "", b = "";
    cin >> a >> b;
    v.push_back(a);
    v.push_back(b);
    cin >> a >> b;
    v.push_back(a);
    v.push_back(b);
    sort(v.begin(), v.end());
    dfs();
    return 0;
}