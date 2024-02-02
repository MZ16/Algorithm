#include <bits/stdc++.h>
using namespace std;

char _map[303][303];
int visited[303][303];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int N, M;
int stY, stX, edY, edX;
int depth;

void bfs() {
	visited[stY][stX] = 1;
	queue<int>q;
	q.push(stY * 1000 + stX);
	while (_map[edY][edX] != '0') {
		queue<int> tmp;
		while (!q.empty()) {
			int y = q.front() / 1000;
			int x = q.front() % 1000;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])continue;
				visited[ny][nx] = 1;
				if (_map[ny][nx] != '0') {
					_map[ny][nx] = '0';
					tmp.push(ny * 1000 + nx);
					continue;
				}
				q.push(ny * 1000 + nx);
			}
		}
		depth++;
		q = tmp;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cin >> stY >> stX >> edY >> edX;
	stY--, stX--, edY--, edX--;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> _map[i][j];
	}
	bfs();
	cout << depth;
	return 0;
}

/*
* '#' - 타겟, '1' - 벽, '0' - 이동가능
* 타겟과 벽을 0으로 바꾸며 진행하는 bfs이다
* 매 depth마다 벽에 막혀 이동 불가능할때까지 순회 할 수 

*/