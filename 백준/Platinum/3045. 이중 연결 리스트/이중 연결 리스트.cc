#include <bits/stdc++.h>
using namespace std;
int dp[500001];
bool Find[500001];
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;
Node* List[500001];
Node* create() {
	return (Node*)malloc(sizeof(Node));
}
void init(Node* head) {
	head->left = head->right = head;
}
void insert(Node* prev, int num) {
	Node* New = create();
	New->data = num;
	New->left = prev;
	New->right = prev->right;
	prev->right->left = New;
	prev->right = New;
	List[num] = New;
}
void Delete(Node* head, Node* removed) {
	if (head == removed) {
		return;
	}
	removed->right->left = removed->left;
	removed->left->right = removed->right;
	free(removed);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0, m = 0;
	cin >> n >> m;
	Node* head = create();
	init(head);
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			insert(head, i);
		}
		else {
			insert(List[i - 1], i);
		}
	}
	for (int i = 0; i < m; i++) {
		char command;
		int target = 0, in = 0;
		cin >> command >> in >> target;
		if (command == 'B') {
			Delete(head, List[in]);
			insert(List[target], in);
		}
		else if (command == 'A') {
			Delete(head, List[in]);
			if (List[target]->left == head) {
				insert(head, in);
			}
			else {
				insert(List[target]->left, in);
			}
		}
	}
	vector<int>ary;
	for (Node* i = head->right; i != head; i = i->right) {
		ary.push_back(i->data);
	}
	int idx = 0;
	dp[0] = ary[0];
	vector<int>log;
	log.push_back(0);
	for (int i = 1; i < n; i++) {
		if (dp[idx] < ary[i]) {
			dp[++idx] = ary[i];
			log.push_back(idx);
		}
		else {
			int start = 0, end = idx, mid = 0;
			while (start < end) {
				mid = (start + end) / 2;
				if (dp[mid] >= ary[i]) {
					end = mid;
				}
				else {
					start = mid + 1;
				}
			}
			dp[end] = ary[i];
			log.push_back(end);
		}
	}
	cout << n - idx - 1 << '\n';
	for (int i = n - 1; i >= 0; i--) {
		if (log[i] == idx) {
			Find[ary[i]] = true;
			idx--;
		}
	}
	vector<int>nf;
	for (int i = 1; i <= n; i++) {
		if (!Find[i]) {
			nf.push_back(i);
		}
	}
	for (int i = 0; i < nf.size(); i++) {
		if (!Find[nf[i]]) {
			if (Find[nf[i] - 1] && nf[i] != 1) {
				cout << "B " << nf[i] << ' ' << nf[i] - 1 << '\n';
				Find[nf[i]] = true;
			}
		}
	}
	for (int i = nf.size() - 1; i >= 0; i--) {
		if (!Find[nf[i]]) {
			if (Find[nf[i] + 1] && nf[i] != n) {
				cout << "A " << nf[i] << ' ' << nf[i] + 1 << '\n';
				Find[nf[i]] = true;
			}
		}
	}
	return 0;
}