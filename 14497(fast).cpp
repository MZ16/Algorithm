#include <bits/stdc++.h>
using namespace std;

const int MAX = 301;
char arr[MAX][MAX];
int visited[MAX][MAX];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int N, M;
int st1, st2, ed1, ed2;
int cnt;

void bfs() {
	visited[st1][st2] = 1;
	queue<int> q;
	q.push(st1*1000+st2);
	while (arr[ed1][ed2] != '0') {
		queue<int> tmp;
		cnt++;
		while (!q.empty()) {
			int y = q.front() / 1000;
			int x = q.front() % 1000;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])continue;
				visited[ny][nx] = 1;
				if (arr[ny][nx] != '0') {
					tmp.push(ny*1000+nx);
					arr[ny][nx] = '0';
					continue;
				}
				q.push(ny*1000+nx);
			}
		}
		q = tmp;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	cin >> st1 >> st2 >> ed1 >> ed2;
	st1--, st2--, ed1--, ed2--;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	bfs();
	cout << cnt;
	return 0;
}

/*
기존의 풀이는 재귀함수의 깊이가 깊어져 80ms가 나왓지만 flood fill을 사용하면 4ms가 나온다.

두개의 큐를 사용
0일경우 q(0), 0이 아니라면(1,#) tmp큐에 담고 arr는 0으로 바꿔준다.
큐가 사라질때까지 반복 후 끝났다면 tmp값을 q에 담아준다.
*/