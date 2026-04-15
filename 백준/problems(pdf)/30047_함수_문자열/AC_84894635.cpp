#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str = "";
    cin >> str;
    stack<int>s;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == 'x') {
            s.push(0);
        }
        else if (str[i] == 'g') {
            if (!s.empty()) {
                int temp = s.top();
                s.pop();
                s.push(temp + 1);
            }
            else {
                cout << -1;
                return 0;
            }
        }
        else if (str[i] == 'f') {
            if (s.size() <= 1) {
                cout << -1; 
                return 0;
            }
            else {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(min(a, b));
            }
        }
    }
    if (s.size() == 1) {
        cout << s.top();
    }
    else {
        cout << -1;
    }
    return 0;
}