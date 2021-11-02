#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
using namespace std;

int TC, N, M, K;
bool visited[51][51];
int arr[51][51];

//상하좌우
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int nx,ny,i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];

		//인덱스 초과 방지
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)continue;
		
		//배열을 방문했거나 지렁이가 없음
		if (visited[ny][nx] || arr[ny][nx] == 0)continue;
		dfs(ny, nx);		
	}
}

int main() {	
	scanf("%d", &TC);
	for (int r = 0; r < TC; r++) {
		int cnt = 0;
		scanf("%d %d %d", &N, &M, &K);
		for (int y,x,j = 0; j < K; j++) {
			scanf("%d %d", &y, &x);
			arr[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
			{
				//지렁이가 있는데 방문하지 않은경우
				if (arr[i][j] && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}					
			}
		}
		printf("%d\n", cnt);
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
	}
	return 0;
}
