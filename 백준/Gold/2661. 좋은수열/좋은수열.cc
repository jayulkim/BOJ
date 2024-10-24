#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string result = "1";
ll n = 0;
bool check(string str) {
    for (int i = 1; i <= str.length() / 2; i++) {
        string a = "", b = "";
        for (int j = 0; j < i; j++) {
            a += str[str.length() - 1 - j];
            b += str[str.length() - 1 - i - j];
        }
        if (a == b) {
            return false;
        }
    }
    return true;
}
bool Find = false;
void dfs() {
    if (Find) {
        return;
    }
    if (result.length() == n) {
        cout << result;
        Find = true;
        return;
    }
    for (int i = 1; i <= 3; i++) {
        result += (char)(i + 48);
        if (check(result)) {
            dfs();
        }
        result.pop_back();
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dfs();
    return 0;
}