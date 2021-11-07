#include <iostream>
#include<algorithm>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 101
using namespace std;
//dfs는 시간초과, 최단거리는 bfs
typedef pair<int, int> pii;
int chk[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
char map[MAX_LEN][MAX_LEN];
int dyx[4][2] = { {1,0},{-1,0},{0,-1},{0,1} }; // 상하좌우
int N, M;

void bfs(int y, int x) {
	visited[y][x] = 1;
	queue<pii>q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dyx[i][0];
			int nx = x + dyx[i][1];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M||visited[ny][nx]||map[ny][nx]=='0')
				continue;//미로 범위
			chk[ny][nx] = chk[y][x] + 1;
			visited[ny][nx] = 1;
			q.push(make_pair(ny, nx));				
		}
	}
}



int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%s", &map[i]);

	bfs(0, 0);
	printf("%d", chk[N - 1][M - 1]+1);
	return 0;
}