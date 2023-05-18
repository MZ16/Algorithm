#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> v;
int N, M;
char arr[54][54];
int visited[54][54];
int dy[4] = { -1,0,1,0 }; // ÇÏ¿ì»óÁÂ
int dx[4] = { 0,1,0,-1 };
int _max, ans;

void bfs(int y, int x) {
	queue<pii> q;
	visited[y][x] = 1;
	q.push({ y,x });
	while (!q.empty()) {
		int hy, hx,tmp=0;
		tie(hy, hx) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = hy + dy[i];
			int nx = hx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] || arr[ny][nx]!='L')continue;
			visited[ny][nx] = visited[hy][hx] + 1;
			tmp = visited[ny][nx];
			_max = max(tmp, _max);
			q.push({ ny,nx });
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'L') {
				bfs(i, j);
				ans = max(_max, ans);
				memset(visited, 0, sizeof(visited));
			}
		}
	}

	cout << ans-1;
	return 0;
}