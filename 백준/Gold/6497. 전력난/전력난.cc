#include <bits/stdc++.h>
using namespace std;
int parent[200001];
int result = 0;
void init(int n) {
    for (int i = 0; i < n; i++) {
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
    if (a > b) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
    }
}
struct info {
    int start;
    int end;
    int weight;
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
        a = getParent(temp.start);
        b = getParent(temp.end);
        if (a != b) {
            merge(a, b);
            result += temp.weight;
            count++;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1) {
        int m = 0, n = 0;
        cin >> m >> n;
        if (m == 0 && n == 0) {
            break;
        }
        init(m);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int start = 0, end = 0, weight = 0;
            cin >> start >> end >> weight;
            sum += weight;
            pq.push({start, end, weight});
        }
        kruskal(m);
        cout << sum - result << '\n';
        result = 0;
        memset(parent, 0, sizeof(parent));
        priority_queue<info, vector<info>, cmp>().swap(pq);
    }
    return 0;
}
