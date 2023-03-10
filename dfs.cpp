#include <bits/stdc++.h>
using namespace std;

// 1은 육지, 0은 바다이며 연결된 육지는 하나의 육지이다.
// 입력 - 맵의 새로길이 N과 가로길이 M이 주어지고 1<=N,M<=100의 범위를 가진다.
// 출력 - 육지의 수를 출력하라.

const int V = 101;
const int yx = 4;
int dy[yx] = { -1,0,1,0 };
int dx[yx] = { 0,1,0,-1 };
int arr[V][V];
bool visited[V][V];
int cnt;
int N, M;

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int j = 0; j < yx; j++) {
		int ny = y + dy[j];
		int nx = x + dx[j];
		if (ny<0 || ny > N || nx<0 || nx>M) continue;
		if (arr[ny][nx] && !visited[ny][nx])dfs(ny, nx);
	}
	return;
}


int main() {
	
	cin >> N>>M;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> arr[i][j];
			
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 값이 존재하고 방문하지 않았을경우
			// dfs호출 시 연결된 모든 노드를 순회 후 종료되기 떄문에 cnt를 여기서 증가시킨다.
			if (!visited[i][j] && arr[i][j]) { dfs(i, j); cnt++; } 
			
		}
	}
	cout << cnt;
	return 0;
}