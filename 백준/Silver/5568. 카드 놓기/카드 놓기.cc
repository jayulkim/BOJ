#include <bits/stdc++.h>
using namespace std;
map<string, int>Map;
int n = 0, m = 0;
vector<string>v;
vector<string>ary;
int result = 0;
bool visited[11];
void dfs() {
    if (ary.size() == m) {
        string temp = "";
        for (auto& j : ary) {
            temp += j;
        }
        if (Map.find(temp) == Map.end()) {
            Map[temp]++;
            result++;
        }
        return;
    }
    for (int j = 0; j < n; j++) {
        if (!visited[j]) {
            visited[j] = true;
            ary.push_back(v[j]);
            dfs();
            visited[j] = false;
            ary.pop_back();
        }
    }
}
int main(void) {
	ios::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> m;
    for (int j = 0; j < n; j++) {
        string num = "";
        cin >> num;
        v.push_back(num);
    }
    dfs();
    cout << result;
	return 0;
}