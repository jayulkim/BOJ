#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string str = "", result = "";
vector<pair<int, int>>v;
vector<int>idx;
vector<string>ary;
stack<char>s;
map<string, int>m;
int temp = -1;
bool visited[11];
bool del[201];
void dfs(int size) {
    if (size == idx.size()) {
        string s = "";
        for (auto& i : idx) {
            del[v[i].first] = true;
            del[v[i].second] = true;
        }
        for (int i = 0; i < str.length(); i++) {
            if (!del[i]) {
                s += str[i];
            }
        }
        if (!m[s]) {
            ary.push_back(s);
            m[s]++;
        }
        memset(del, false, sizeof(del));
        return;
    }
    for (int i = temp + 1; i < v.size(); i++) {
        if (!visited[i]) {
            idx.push_back(i);
            visited[i] = true;
            temp = i;
            dfs(size);
            visited[i] = false;
            idx.pop_back();
        }
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(i);
        }
        else if (str[i] == ')') {
            int t = s.top();
            s.pop();
            v.push_back({ t, i });
        }
    }
    for (int i = 1; i <= v.size(); i++) {
        dfs(i);
        temp = -1;
    }
    sort(ary.begin(), ary.end());
    for (auto& i : ary) {
        cout << i << '\n';
    }
    return 0;
}