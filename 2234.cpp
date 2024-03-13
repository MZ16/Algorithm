#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;
typedef pair<int, int> pii;
int N, M;
int MAP[MAX][MAX];
int visited[MAX][MAX];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

void Input() {
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> MAP[i][j];
	return;
}

int Bfs(int y, int x) {
	int RoomSize = 0;
	queue<pii> q;
	q.push({ y,x });
	visited[y][x] = 1;
	RoomSize++;
	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();
		int wall = 1;
		for (int i = 0; i < 4; i++) {
			if (!(MAP[y][x] & wall)) { // 비트연산을 통해 벽의 위치를 파악한다
				int nx = x + dx[i];
				int ny = y + dy[i];
				// continue를 사용할 경우 wall의 쉬프트는 위쪽에서 해야한다.
				if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[ny][nx]) { 
					RoomSize++;
					visited[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
			wall *= 2;
		}
	}
	return RoomSize;
}

void Soluetion() {
	int RoomCnt = 0;
	int BiggestRoomSize = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				BiggestRoomSize = max(BiggestRoomSize, Bfs(i, j));
				RoomCnt++;
			}
		}
	}

	cout << RoomCnt<<"\n";
	cout << BiggestRoomSize << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int wall = 1; wall < 16; wall *= 2) {
				if ((MAP[i][j] & wall)) {
					memset(visited, 0, sizeof(visited));
					MAP[i][j] -= wall;
					BiggestRoomSize = max(Bfs(i, j),BiggestRoomSize);
					MAP[i][j] += wall;
				}
			}
		}
	}
	cout << BiggestRoomSize;
	return;
}

void Solve() {
	Input();
	Soluetion();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	Solve();

	return 0;
}

/*
1. Room의 개수
2. 제일 큰 Room의 크기
3. 벽 하나를 부수고 가장 큰 Room의 크기

비트연산을 통해 벽의 위치를 파악하고 위 3가지를 출력하는 문제이다.
BFS에서 벽이 없는 경우만 탐색을 진행하는 로직만 추가하여 Room의 크기를 반환하면 된다.
가장 큰 방도 반환값을 max를 통해 구하면 된다.
벽을 부수는것은 벽이 있는 경우를 조건으로 추가하여 벽의 비트값을 맵에서 빼주면 된다.
연산이 끝난 후 벽의 비트를 다시 더해줘야한다.
벽을 부수는 과정은 모든 맵과 벽을 확인해야 하므로 매번 방문배열을 초기화시켜준다.

문제 조건에서 서=1, 북=2, 동=4, 남=8 이라 주어져서 방향벡터를 북을 1, 남을 -1로
설정하는 실수를 범해 시간을 오래 썻다.


*/