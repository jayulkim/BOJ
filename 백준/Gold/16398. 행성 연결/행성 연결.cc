#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int parent[1001];
int getparent(int x) {
    if (parent[x] == x) {
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
ll result = 0;
struct info {
    int start;
    int end;
    ll weight;
    
};
struct cmp {
    bool operator()(const info& a, const info& b) {
        return a.weight > b.weight;
    }  
};
priority_queue<info, vector<info>, cmp>pq;
void kruskal(int n) {
    int count = 0, a = 0, b = 0;
    while (count < n - 1) {
        info temp = pq.top();
        pq.pop();
        a = getparent(temp.start);
        b = getparent(temp.end);
        if (a != b) {
            result += temp.weight;
            count++;
            merge(a, b);
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll weight = 0;
            cin >> weight;
            if (j >= i + 1) {
                pq.push({i, j, weight});
            }
        }
    }
    kruskal(n);
    cout << result;
    return 0;
} 