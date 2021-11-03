#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int arr[1001][1001];
bool visited[1001];
int N, M, V;

void dfs(int v) {
	visited[v] = 1;
	cout << v << " ";
	for (int i = 1; i <= N; i++) {
		if (arr[v][i] == 0 || visited[i])continue;
		dfs(i);
	}
}

void bfs(int v) {
	queue <int> q;	
	visited[v] = 1;
	q.push(v);
	while (!q.empty()) {
		cout << q.front() << ' ';
		int x = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (arr[x][i] == 0 || visited[i])continue;
			q.push(i);
			visited[i] = 1;
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);
	for (int v1, v2, i = 0; i < M; i++) {
		scanf("%d %d", &v1, &v2);
		arr[v1][v2] = 1;
		arr[v2][v1] = 1;
	}
	dfs(V);
	memset(visited, false, sizeof(visited));
	printf("\n");
	bfs(V);

	return 0;
}