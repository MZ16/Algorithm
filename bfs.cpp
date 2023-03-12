#include <bits/stdc++.h>
using namespace std;
// ����ġ�� ���� �ִܰŸ��� ����ϴ� �����̴�. ( 1 <= N,M <= 100 )
// �Է� - ���� ũ�� N, M�� �־����� �¿����� ��ġ(y,x)�� ������(y,x)�� �־�����.
// ��� - �̵��Ÿ� ���

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int arr[102][102];
int visited[102][102]; // ����ġ �ο��� ���� bool type�� �ƴ� int�� ����

int N, M;
int my, mx;
int ey, ex;

//tie - pair, tuple�� �ٸ��� tie�� ���� ������ ���� ����� �� �ִ�.
int hy, hx;

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });
	while (!q.empty()) {
		cout << q.front().first << " : " << q.front().second << "\n";
		//pair<int, int> h = q.front();
		tie(hy, hx) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = hy + dy[i];
			int nx = hx + dx[i];
			if (ny<0 || ny>N || nx<0 || nx>M)continue;
			if (!arr[ny][nx] || visited[ny][nx]) continue;
			//visited[ny][nx] = visited[h.first][h.second] + 1;
			visited[ny][nx] = visited[hy][hx] + 1;
			q.push({ ny,nx });
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// �迭 ũ��, ��������, ������
	cin >> N >> M >> my >> mx >> ey >> ex;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	
	bfs(my, mx);
	cout << visited[ey][ex];


	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
		}cout << "\n";
	}*/
	return 0;
}