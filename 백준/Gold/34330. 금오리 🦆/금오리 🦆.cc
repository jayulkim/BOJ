#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 모든 연꽃 DFS or BFS
// ㄴ 건너갈 수 있는 것 들만 (연꽃 - 오리)^2 <= L^2 + 연꽃 반지름^2
// 오리 좌표 제곱 + L 제곱 >= R^2
// L이 R보다 길때 계산 생각
// ㄴ 모든 오리 잡을 수 있음 N
int main() {
    ll R, L, N, M, cnt = 0;
    cin >> R >> L >> N >> M;

    if (R <= L) {
        cout << M;
        exit(0);
    }

    vector<tuple<ll, ll, ll>> totus;
    vector<pair<ll, ll>> duck;
    vector<bool> flag(M, false);
    vector<bool> visit(N, false);

    for (int i = 0; i < N; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        totus.push_back({ b, a, c });
    }

    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        duck.push_back({ b, a });
    }


    //BFS
    queue<int> q;
    for (int i = 0; i < N; i++) {
        ll y = get<0>(totus[i]);
        ll x = get<1>(totus[i]);
        ll r = get<2>(totus[i]);

        ll dis = y * y + x * x;
        if ((R - r) <= 0 || dis >= (R - r) * (R - r)) {
            q.push(i);
            visit[i] = true;
        }
    }

    while (q.size()) {
        int here = q.front();
        ll y = get<0>(totus[here]);
        ll x = get<1>(totus[here]);
        ll r = get<2>(totus[here]);

        q.pop();

        for (int i = 0; i < N; i++) {
            if (visit[i] == true) continue;
            ll ny = get<0>(totus[i]);
            ll nx = get<1>(totus[i]);
            ll nr = get<2>(totus[i]);

            ll dis = ((y - ny) * (y - ny)) + ((x - nx) * (x - nx));
            if (dis <= (r + nr) * (r + nr)) {
                q.push(i);
                visit[i] = true;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        ll dy = duck[i].first;
        ll dx = duck[i].second;

        ll dist = (dy * dy) + (dx * dx);
        if (dist >= ((R - L) * (R - L))) {
            cnt++;
            flag[i] = true;
        }

        if (flag[i]) continue;
        for (int j = 0; j < N; j++) {
            if (visit[j]) {
                ll ty = get<0>(totus[j]);
                ll tx = get<1>(totus[j]);
                ll tr = get<2>(totus[j]);

                ll dis = ((ty - dy) * (ty - dy)) + ((tx - dx) * (tx - dx));
                if (dis <= ((tr + L) * (tr + L))) {
                    cnt++;
                    flag[i] = true;
                    break;
                }
            }
        }
    }

    cout << cnt;
}