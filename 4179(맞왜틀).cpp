#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

typedef pair<int, int> pii;

int N, M, y, x;
char arr[1004][1004];
int fire_visited[1004][1004];
int people_visited[1004][1004];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
queue<pii> q;
pii pp;
int ans;

void fire_bfs() {
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue; // fire �湮ó���� INF�� �ʱ�ȭ �ϱ⶧���� INF�� �ƴҰ��� ó����
			if (arr[ny][nx] == '#' || fire_visited[ny][nx]!=INF)continue; // INF - �ݷ�ó��
			fire_visited[ny][nx] = fire_visited[y][x]+1;
			q.push({ ny,nx });
		}
		
	}
	return;
}

void people_bfs() {
	people_visited[pp.first][pp.second] = 1;
	q.push(pp);
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		if (y == 0 || y == N - 1 || x == 0 || x == M - 1) {
			ans = people_visited[y][x];
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || people_visited[ny][nx])continue;
			if (arr[ny][nx] == '#'|| people_visited[y][x] + 1 >= fire_visited[ny][nx])continue; // ���� ����ġ�� �������� �ʾƼ� +1
			people_visited[ny][nx] = people_visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	fill(&fire_visited[0][0], &fire_visited[0][0] + 1004 * 1004, INF); // �ݷ� ó�� (�Ʒ� �ּ��� �ΰ� ����)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'J') { pp.first = i; pp.second = j; }
			if (arr[i][j] == 'F') { 
				fire_visited[i][j] = 1;
				q.push({ i,j });
			}
		}
	}
	fire_bfs();
	people_bfs();
	
	if (ans) cout << ans;
	else cout << "IMPOSSIBLE";

	return 0;
}
/* �������� ��ǥ�� 1���� �־����ٰ� ������ ���������� ���� �׷��� �ʱ� ������ �������� �� �� �ִ�.
* ���� ����ġ�� ���� �� �������� ����ġ�� �Һ��� ���� ��츸 bfs�� �����ϸ� �ȴ�.
*/

/* 61% Ʋ, ���� ����
* �̷ο� ���� ���ų� ������ ���Ѵٸ� ��� ���� 0�̾ �����̰� ������ �� �����ϴ�.
* ���� x,y������ �ּҺ���� ����� �� �ѹ��� �湮�� ���� ���� ���̶�� 
* Integer.MAX_VALUE���� �ſ� ū ������ �ʱ�ȭ�ؼ� ����մϴ�.
* �߰��� memset�� 0�� -1�θ� �ʱ�ȭ �����ϴ� fill�� �ʱ�ȭ �� ��
*/

/*
7 7
#######
#J###F#
#.....#
#.#.#.#
#.#.#.#
F.#.#.#
#####.#
*/