#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>result;
string str = "";
bool visited[51];
bool Find = false;
ll getmax(ll len) {
    if (len <= 9) {
        return len;
    }
    return 9 + (len - 9) / 2;
}
void dfs(ll n, ll start) {
    if (Find) {
        return;
    }
    if (result.size() == n) {
        for (auto& i : result) {
            cout << i << ' ';
        }
        Find = true;
        return;
    }
    if (start + 1 < str.length()) {
        string temp = "";
        temp += str[start];
        temp += str[start + 1];
        ll num = stoll(temp);
        if (!visited[num] && num <= n && num > 0) {
            visited[num] = true;
            result.push_back(num);
            dfs(n, start + 2);
            visited[num] = false;
            result.pop_back();
        }
        temp = "";
        temp += str[start];
        num = stoll(temp);
        if (!visited[num] && num <= n && num > 0) {
            visited[num] = true;
            result.push_back(num);
            dfs(n, start + 1);
            visited[num] = false;
            result.pop_back();
        }
    }
    else if (start < str.length()) {
        string temp = "";
        temp += str[start];
        ll num = stoll(temp);
        if (!visited[num] && num <= n && num > 0) {
            visited[num] = true;
            result.push_back(num);
            dfs(n, start + 1);
            visited[num] = false;
            result.pop_back();
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    dfs(getmax(str.length()), 0);
    return 0;
}