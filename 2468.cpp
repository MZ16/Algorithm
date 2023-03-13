#include <bits/stdc++.h>
using namespace std;

// dfs문제, 단 0대신 특정 수 이하라는 조건으로 주어짐
// 2 <= N <= 100, 1 <= height <= 100
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int N; 
int adj[101][101];
int visited[101][101];
int ret;


/* 73% */
void dfs(int y, int x, int k) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny>=N || nx<0 || nx>=N)continue;
		if (adj[ny][nx] > k && !visited[ny][nx]) dfs(ny, nx, k); 
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> adj[i][j];
		
	
	int result = 1;
	// 오답노트, 아무것도 물에 잠기지 않을 수 있다 / height를 0부터 하거나 안전지대 변수를 1로 두는 방법으로 처리할 수 있음
	for (int k = 1; k <= 100; k++) { // height
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (adj[i][j] > k && !visited[i][j]) { ret++; dfs(i, j,k); }
			}
		}
		result = max(result, ret);
		memset(visited, 0, sizeof(visited)); ret = 0;
	}
	
	
	cout << result;


	return 0;
}