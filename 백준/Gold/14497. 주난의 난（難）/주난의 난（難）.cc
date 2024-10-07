#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;
ll dist[301][301];
int Forward[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char Map[301][301];
struct pos {
    int y;
    int x;
    ll weight;
};
struct cmp {
    bool operator()(const pos& a, const pos& b) {
        return a.weight > b.weight;
    }
};
priority_queue<pos, vector<pos>, cmp>pq;
void dijkstra(int y, int x, int n, int m) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            dist[j][k] = INF;
        }
    }
    dist[y][x] = (ll)(Map[y][x] - 48);
    pq.push({y, x, (ll)(Map[y][x] - 48)});
    while(!pq.empty()) {
        pos temp = pq.top();
        pq.pop();
        if (dist[temp.y][temp.x] >= temp.weight) {
            for (int j = 0; j < 4; j++) {
                int dy = temp.y + Forward[j][0];
                int dx = temp.x + Forward[j][1];
                if (dy < n && dy >= 0 && dx < m && dx >= 0) {
                    if (dist[dy][dx] > dist[temp.y][temp.x] + (ll)(Map[dy][dx] - 48)) {
                        dist[dy][dx] = dist[temp.y][temp.x] + (ll)(Map[dy][dx] - 48);                     
                        pq.push({dy, dx, dist[dy][dx]});
                    }
                }
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 0, m = 0;
    cin >> n >> m;
    int starty = 0, startx = 0;
    int endy = 0, endx = 0;
    cin >> starty >> startx >> endy >> endx;
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            cin >> Map[j][k];
            if (Map[j][k] == '#') {
                Map[j][k] = '1';
            }
            else if (Map[j][k] == '*') {
                Map[j][k] = '0';
            }
        }
    }
    dijkstra(starty - 1, startx - 1, n, m);
    cout << dist[endy - 1][endx - 1];
    return 0;
}