#include <bits/stdc++.h>
using namespace std;
int parent[300001];
int n = 0;
int getparent (int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = getparent(parent[x]);
}
void merge(int a, int b) {
    a = getparent(a);
    b = getparent(b);
    if (a > b) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
    }
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(0);
	cin >> n;
    for (int j = 1; j <= n; j++) {
        parent[j] = j;
    }
    for (int j = 0; j < n - 2; j++) {
        int start = 0, end = 0;
        cin >> start >> end;
        merge(start, end);
    }
    vector<int>v;
    for (int j = 1; j <= n; j++) {
        v.push_back(getparent(j));
    }
    sort(v.begin(), v.end());
    for(int j = 0; j < v.size() - 1; j++) {
        if (v[j] != v[j + 1]) {
            cout << v[j] << ' ' << v[j + 1];
            return 0;
        }
    }
	return 0;
}