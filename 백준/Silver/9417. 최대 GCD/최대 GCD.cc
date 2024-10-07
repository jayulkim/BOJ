#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    int temp = a % b;
    while (temp > 0) {
        a = b;
        b = temp;
        temp = a % b;
    }
    return b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num = 0;
    cin >> num;
    cin.ignore();
    while (num--) {
        string str = "";
        getline(cin, str);
        vector<int>v;
        string temp = "";
        for (int i = 0; i < str.length(); i++) {
            if(str[i] == ' ') {
                v.push_back(stoi(temp));
                temp = "";
            }
            else {
                temp += str[i];
            }
        }
        if (temp != "") {
            v.push_back(stoi(temp));
        }
        int Max = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            for (int j = i + 1; j < v.size(); j++) {
                Max = max(Max, gcd(v[i], v[j]));
            }
        }
        cout << Max << '\n';
    }
    return 0;
}