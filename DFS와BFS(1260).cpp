#include<iostream>
#include<cstring>
#include<queue>
using namespace std;


int arr[1001][1001];
bool visited[1001];
int N, M, V;

void dfs(int x) {
	cout << x << ' ';
	visited[x] = 1;	
	for (int i = 1; i <= N; i++) {
		//연결되지 않은 간선이거나 방문한 정점이라면
		if (arr[x][i] == 0 || visited[i]) continue;
		dfs(i);
	}
}

void bfs(int x) {
	queue<int> q;
	visited[x] = 1;
	q.push(x);
	while (!q.empty()) {
		cout << q.front() << ' ';
		int v = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (arr[v][i] == 0 || visited[i])continue;
			q.push(i);
			visited[i] = 1;
		}
	}
}

int main() {
	cin >> N >> M >> V;
	for (int v1, v2, i = 0; i < M; i++) {
		cin >> v1 >> v2;
		arr[v1][v2] = 1;
		arr[v2][v1] = 1;
	}

	dfs(V); 
	memset(visited, false, sizeof(visited));
	cout << "\n";
	bfs(V);
	return 0;
}
