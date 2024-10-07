#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str = "";
    cin >> str;
    int count = 0;
    for (auto& i : str) {
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
            count++;
        }
    }
    cout << count;
    return 0;
}