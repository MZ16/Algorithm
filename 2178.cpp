#include <bits/stdc++.h>
using namespace std;

// bfs를 이용한 가중치가 같은 최단거리를 구하는 문제이다.
// 범위 - 2 <= N,M <= 100
// 시작 위치와 도착 위치도 가중치에 포함된다.

int N, M;
int adj[102][102];
int visited[102][102];
// 하우상좌
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int hy, hx;

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y,x });
	while (!q.empty()) {
		tie(hy, hx) = q.front(); 
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = hy + dy[i];
			int nx = hx + dx[i];
			if (ny<0 || ny>N || nx<0 || nx>M)continue;
			if (!adj[ny][nx] || visited[ny][nx])continue;
			visited[ny][nx] = visited[hy][hx] + 1;
			q.push({ ny,nx });
		}
	}
	return;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &adj[i][j]);
		}
	}
	bfs(0,0);
	//debug
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
		}cout << "\n";
	}*/
	cout << visited[N-1][M-1];
	return 0;
}