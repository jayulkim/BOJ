#include <bits/stdc++.h>
using namespace std;
int parent[501];
bool cycle[501];
bool graph[501];
bool tree[501];
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
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num = 1;
    while (1) {
        int n = 0, m = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < m; i++) {
            int start = 0, end = 0;
            cin >> start >> end;
            if (getParent(start) != getParent(end)) {
                merge(start, end);
            }
            else {
                cycle[start] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            parent[i] = getParent(i);
        }
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (cycle[i]) {
                graph[parent[i]] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!graph[parent[i]]) {
                tree[parent[i]] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (tree[i]) {
                result++;
            }
        }
        if (result == 1) {
            cout << "Case " << num << ": " << "There is one tree." << '\n';
        }
        else if (result == 0) {
            cout << "Case " << num << ": " << "No trees." << '\n';
        }
        else {
            cout << "Case " << num << ": " << "A forest of " << result << " trees." << '\n';
        }
        num++;
        memset(parent, 0, sizeof(parent));
        memset(cycle, false, sizeof(cycle));
        memset(graph, false, sizeof(graph));
        memset(tree, false, sizeof(tree));
    }
    return 0;
}