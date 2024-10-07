#include <bits/stdc++.h>
using namespace std;
int parent[10001];
int result[10001];
vector<int>v;
void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}
int getParent(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = getParent(parent[x]);
}
void merge(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (v[a] > v[b]) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    init(n);
    v.push_back(0);
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        v.push_back(num);
    }
    for (int i = 0; i < m; i++) {
        int start = 0, end = 0;
        cin >> start >> end;
        merge(start, end);
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = getParent(i);
    }
    for (int i = 1; i <= n; i++) {
        result[parent[i]]++;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (result[i] != 0) {
            sum += v[i];
        }
    }
    if (sum > k) {
        cout << "Oh no";
    }
    else {
        cout << sum;
    }
    return 0;
}