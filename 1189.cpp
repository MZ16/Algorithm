#include <bits/stdc++.h>
using namespace std;

int R, C, K;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[7][7];
string arr[7];
int ans;


void dfs(int y, int x) {
	if (y == 0 && x == C - 1 && visited[y][x]==K) {
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] || arr[ny][nx] == 'T')continue;
		visited[ny][nx] = visited[y][x] + 1;
		dfs(ny, nx);
		visited[ny][nx] = 0;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}
	visited[R - 1][0] = 1;
	dfs(R-1, 0);
	cout << ans;
	return 0;
}

/*  완탐하기에 문제없는 시간복잡도이며 백트레킹 문제이다.
*	dfs로 방향탐색을 한다.
*	목적지 방문배열 가중치가 K와 같다면 카운트를 증가시키고 반환한다.
*	위의 경우 혹은 더 이상 탐색이 불가능하다면 백트레킹
* 
실수한 부분
	문제 조건 중 T의 위치는 시작점에 올 수 없다란 말이 없는데 고려하지 않은점 (실제론 번역오류로 원문에는 있음)
	시작점을 왼쪽 아래 도착점을 오른쪽 위라고 명시 했음에도 시작점을 0,0으로 생각한점
*/