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
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue; // fire 방문처리는 INF로 초기화 하기때문에 INF가 아닐경우로 처리함
			if (arr[ny][nx] == '#' || fire_visited[ny][nx]!=INF)continue; // INF - 반례처리
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
			if (arr[ny][nx] == '#'|| people_visited[y][x] + 1 >= fire_visited[ny][nx])continue; // 아직 가중치를 더해주지 않아서 +1
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

	fill(&fire_visited[0][0], &fire_visited[0][0] + 1004 * 1004, INF); // 반례 처리 (아래 주석에 부가 설명)
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
/* 지훈이의 좌표는 1개만 주어진다고 지문에 쓰여있지만 불은 그렇지 않기 때문에 여러개가 올 수 있다.
* 불의 가중치를 구한 후 지훈이의 가중치가 불보다 작을 경우만 bfs를 진행하면 된다.
*/

/* 61% 틀, 오답 이유
* 미로에 불이 없거나 퍼지지 못한다면 모든 값이 0이어서 지훈이가 움직일 수 없습니다.
* 보통 x,y까지의 최소비용을 계산할 때 한번도 방문한 적이 없는 곳이라면 
* Integer.MAX_VALUE같은 매우 큰 값으로 초기화해서 사용합니다.
* 추가로 memset은 0과 -1로만 초기화 가능하니 fill로 초기화 할 것
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