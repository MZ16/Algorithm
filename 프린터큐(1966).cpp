#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#pragma warning(disable:4996)
#define pi pair<int, int>
using namespace std;

int TC, N, M, p;


void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init();
	cin >> TC;
	while (TC--) {
		int cnt = 0;
		queue<pi>q;
		priority_queue<int> pq;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> p;
			q.push({ i, p });
			pq.push(p);
		}
		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if (pq.top() == val) {
				pq.pop();
				cnt++;
				if (M == idx) {
					cout << cnt << "\n";
					break;
				}
			}
			else {
				q.push({ idx,val });
			}
		}
	}
}