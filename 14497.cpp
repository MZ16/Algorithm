#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 304;
int N, M;
char _map[MAX][MAX];
char tmp[MAX][MAX];
int visited[MAX][MAX];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
pii start, _end;
int jumpCnt,flag=0;

void bfs(int y, int x) {
	visited[y][x] = 1;
	queue<pii>q;
	q.push({ y,x });
	while (!q.empty()) {		
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])continue;
			if (_map[ny][nx] == '#') { flag = 1; return; }
			if (_map[ny][nx] == '1')tmp[ny][nx] = '0';
			else {
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	cin >> start.first >> start.second >> _end.first >> _end.second;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> _map[i][j];
		}
	}

	while (1) {
		jumpCnt++;
		memset(visited, 0, sizeof(visited));
		memcpy(tmp, _map, sizeof(tmp));
		bfs(start.first - 1, start.second - 1);
		if (flag)break;
		memcpy(_map, tmp, sizeof(_map));
	}
	
	cout << jumpCnt;

	return 0;
}




/*
ù° �ٿ� �ֳ��̰� ��ġ�� ������ ũ�� N, M�� �־�����. (1 �� N, M �� 300)

��° �ٿ� �ֳ����� ��ġ x1, y1�� ������ ��ġ x2, y2�� �־�����. (1 �� x1, x2 �� N, 1 �� y1, y2 �� M)

���� N��M ũ���� ���� ������ �־�����. 0�� �� ����, 1�� ģ��, *�� �ֳ�, #�� ������ ���Ѵ�.
*/