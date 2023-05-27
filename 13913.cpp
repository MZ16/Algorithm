#include <bits/stdc++.h>
using namespace std;
//0 <= N,K <= 100,000 / ( x-1, x+1, 2x )
int N, K;
int visited[200004];
int _prev[200004];
vector<int>ans;

void fastIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	return;
}

void bfs() {
	visited[N] = 1;
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int next : {here - 1, here + 1, 2 * here}) {
			if (next < 0 || next>200000)continue;
			if (!visited[next]) {
				visited[next] = visited[here] + 1;
				_prev[next] = here;
				q.push(next);
			}
		}
	}
	return;
}

int main() {
	fastIO();
	cin >> N >> K;
	if (N == K) {
		cout << 0 << "\n";
		cout << K;
		return 0;
	}
	bfs();
	ans.push_back(K); // 목표지점 초기값
	for (int i = K; i != N; i = _prev[i]) {
		ans.push_back(_prev[i]);
	}
	reverse(ans.begin(), ans.end());
	cout << visited[K] - 1 << "\n";
	for (auto i : ans)cout << i << " ";
	return 0;
}
/*
* trace 사용(최단거리 경로)
* _prev[next] = here 로 정점에서 이어진 간선의 위치를 모두 기록
*/