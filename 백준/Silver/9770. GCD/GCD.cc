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
    string str = "";
    vector<int>v;
    while (getline(cin, str)) {
        string temp = "";
        for (auto& i : str) {
            if (i == ' ') {
                v.push_back(stoi(temp));
                temp = "";
            }
            else {
                temp += i;
            }
        }
        if (temp != "") {
            v.push_back(stoi(temp));
        }
    }
    int Max = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            Max = max(Max, gcd(v[i], v[j]));
        }
    }
    cout << Max;
    return 0;
}