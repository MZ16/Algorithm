#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX_LEN 101
using namespace std;

bool visited[MAX_LEN];
int arr[MAX_LEN][MAX_LEN];
int N, M;
int cnt;

void dfs(int v) {
	visited[v] = 1;
	cnt++;
	for (int i = 1; i <= N; i++) {
		if (visited[i] || arr[i][v] == 0)continue;
		dfs(i);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int x,y,i = 1; i <= M; i++) {
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	dfs(1);
	printf("%d", cnt-1);
	return 0;
}