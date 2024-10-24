#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n = 0, m = 0;
struct mininfo {
	ll start;
	ll end;
	ll weight;
	bool operator()(const mininfo& a, const mininfo& b) {
		return a.weight > b.weight;
	}
};
struct maxinfo {
	ll start;
	ll end;
	ll weight;
	bool operator()(const maxinfo& a, const maxinfo& b) {
		return a.weight < b.weight;
	}
};
priority_queue<mininfo, vector<mininfo>, mininfo>minpq;
priority_queue<maxinfo, vector<maxinfo>, maxinfo>maxpq;
ll parent[1001];
ll getparent(ll x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = getparent(parent[x]);
}
void merge(ll a, ll b) {
	a = getparent(a);
	b = getparent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}
ll minkruskal() {
	ll result = 0;
	ll count = 0;
	while (count < n) {
		mininfo temp = minpq.top();
		minpq.pop();
		if (getparent(temp.start) != getparent(temp.end)) {
			merge(temp.start, temp.end);
			result += temp.weight;
			count++;
		}
	}
	return result * result;
}
ll maxkruskal() {
	ll result = 0;
	ll count = 0;
	while (count < n) {
		maxinfo temp = maxpq.top();
		maxpq.pop();
		if (getparent(temp.start) != getparent(temp.end)) {
			merge(temp.start, temp.end);
			result += temp.weight;
			count++;
		}
	}
	return result * result;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m + 1; i++) {
		ll start = 0, end = 0, weight = 0;
		cin >> start >> end >> weight;
		if (!weight) {
			minpq.push({ start, end, 1 });
			maxpq.push({ start, end, 1 });
		}
		else {
			minpq.push({ start, end, 0 });
			maxpq.push({ start, end, 0 });
		}
	}
	ll Max = maxkruskal();
	parent[0] = 0;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	ll Min = minkruskal();
	cout << Max - Min;
	return 0;
}