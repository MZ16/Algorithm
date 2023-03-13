#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int M, N, K; // 가로, 세로, 개수 / 1<= M,N <= 50, 1<= K <= 2500
int adj[52][52];
int visited[52][52];
int ret;

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny>N || nx<0 || nx>M)continue;
		if (!visited[ny][nx] && adj[ny][nx])dfs(ny, nx);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int TC;
	cin >> TC;
	for (int t = 0; t < TC; t++) {
		cin >> M >> N >> K;
		for (int x, y, i = 0; i < K; i++) { cin >> x >> y; adj[y][x] = 1; }

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && adj[i][j]) { ret++; dfs(i, j); }
			}
		}
		cout << ret<<"\n";
		ret = 0;
		memset(visited, 0, sizeof(visited));
		memset(adj, 0, sizeof(adj));
	}
	
	return 0;
}