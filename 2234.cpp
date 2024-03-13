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
			if (!(MAP[y][x] & wall)) { // ��Ʈ������ ���� ���� ��ġ�� �ľ��Ѵ�
				int nx = x + dx[i];
				int ny = y + dy[i];
				// continue�� ����� ��� wall�� ����Ʈ�� ���ʿ��� �ؾ��Ѵ�.
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
1. Room�� ����
2. ���� ū Room�� ũ��
3. �� �ϳ��� �μ��� ���� ū Room�� ũ��

��Ʈ������ ���� ���� ��ġ�� �ľ��ϰ� �� 3������ ����ϴ� �����̴�.
BFS���� ���� ���� ��츸 Ž���� �����ϴ� ������ �߰��Ͽ� Room�� ũ�⸦ ��ȯ�ϸ� �ȴ�.
���� ū �浵 ��ȯ���� max�� ���� ���ϸ� �ȴ�.
���� �μ��°��� ���� �ִ� ��츦 �������� �߰��Ͽ� ���� ��Ʈ���� �ʿ��� ���ָ� �ȴ�.
������ ���� �� ���� ��Ʈ�� �ٽ� ��������Ѵ�.
���� �μ��� ������ ��� �ʰ� ���� Ȯ���ؾ� �ϹǷ� �Ź� �湮�迭�� �ʱ�ȭ�����ش�.

���� ���ǿ��� ��=1, ��=2, ��=4, ��=8 �̶� �־����� ���⺤�͸� ���� 1, ���� -1��
�����ϴ� �Ǽ��� ���� �ð��� ���� ����.


*/