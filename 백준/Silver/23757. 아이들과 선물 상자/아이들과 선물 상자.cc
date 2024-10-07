#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>>pq;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, m = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        pq.push(num);
    }
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        if (pq.top() < num) {
            cout << 0;
            return 0;
        }
        int temp = pq.top();
        pq.pop();
        temp -= num;
        pq.push(temp);
    }
    cout << 1;
    return 0;
}