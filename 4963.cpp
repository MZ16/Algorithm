#include<bits/stdc++.h>
using namespace std;


int dy[8] = {-1,0,1,0,1,1,-1,-1};
int dx[8] = {0,1,0,-1,1,-1,1,-1}; 
int visited[52][52];
int arr[52][52];
int cnt,N,M;	//	N - X, M - Y

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny>M || nx<0 || nx>N)continue;
		if (visited[ny][nx]==0 && arr[ny][nx] == 1)dfs(ny, nx);
	}
	
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0)break;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		/*for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << " ";
			}cout << "\n";
		}*/
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0 && arr[i][j] == 1) { cnt++; dfs(i,j); }
			}
		}
		cout << cnt << "\n";
		memset(visited, 0, sizeof(visited));
		memset(arr, 0, sizeof(arr));
		cnt = 0;
	}

	return 0;
}

// dfs에 대각선 탐색 추가