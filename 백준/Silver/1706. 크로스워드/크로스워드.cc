#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char Map[21][21];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n = 0, m = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str = "";
        cin >> str;
        for (int j = 0; j < m; j++) {
            Map[i][j] = str[j];
        }
    }
    vector<string>result;
    for (int i = 0; i < n; i++) {
        string temp = "";
        for (int j = 0; j < m; j++) {
            if (Map[i][j] == '#') {
                if (temp.length() > 1) {
                    result.push_back(temp);
                }
                temp = "";
            }
            else {
                temp += Map[i][j];
            }
        }
        if (temp.length() > 1) {
            result.push_back(temp);
        }
    }
    for (int i = 0; i < m; i++) {
        string temp = "";
        for (int j = 0; j < n; j++) {
            if (Map[j][i] == '#') {
                if (temp.length() > 1) {
                    result.push_back(temp);
                }
                temp = "";
            }
            else {
                temp += Map[j][i];
            }
        }
        if (temp.length() > 1) {
            result.push_back(temp);
        }
    }
    sort(result.begin(), result.end());
    cout << result[0];
    return 0;
}