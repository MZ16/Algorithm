#include <bits/stdc++.h>
using namespace std;

// input <= 60

int N;
int visited[62][62][62];
int arr[3];
int _arr[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,1,9},
	{3,9,1},
	{1,9,3},
	{1,3,9}
};
struct Tuple
{
	int a,b,c;
};
queue<Tuple> q;

void bfs(int a, int b, int c) {
	visited[a][b][c] = 1;
	q.push({ a,b,c });
	while (!q.empty()) {
		int ha = q.front().a;
		int hb = q.front().b;
		int hc = q.front().c;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int na = max(0, ha - _arr[i][0]); // max 0 은 음수를 제외하기 위함
			int nb = max(0, hb - _arr[i][1]);
			int nc = max(0, hc - _arr[i][2]);
			if (visited[na][nb][nc])continue; // 방문한 정점 처리
			visited[na][nb][nc] = visited[ha][hb][hc] + 1;
			q.push({ na,nb,nc });
		}
	}
	cout << visited[0][0][0] - 1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> arr[i];
	bfs(arr[0], arr[1], arr[2]);
	return 0;
}

/* map과 좌표, 가중치 bfs문제가 아닌 정점과 간선으로 이루어진 bfs문제이다.
* 주어진 값의 경우의 수 = map의 상하좌우
* if-continue / 방문한 정점 처리 및 가장 낮은 depth의 ans를 구함
*/