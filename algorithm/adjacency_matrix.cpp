#include <bits/stdc++.h>
using namespace std;

// 정점 0 ~ 9, 간선 1-2 / 1-3 / 3-4
// 0번부터 방문 안한 노드를 찾고 해당 노드부터 방문, 연결된 노드를 이어서 방문하는 재귀함수
int adj[10][10];
int visit[10] = { 0, };

void dfs(int i) {
	visit[i] = 1;
	cout << "정점 :  " << i <<"\n";
	for (int j = 0; j < 10; j++) {	// 연결된 간선처리
		if (visit[j])continue;
		if (adj[i][j]) {
			cout << "간선 :  " << i<< "-"<<j << "\n";
			dfs(j);
		}
	}
	return;
}


int main() {

	adj[1][2] = 1;	adj[1][3] = 1;	adj[3][4] = 1;
	adj[2][1] = 1;	adj[3][1] = 1;	adj[4][3] = 1;
	
	
	// 위 재귀함수에선 연결된 간선으로 가는것이라 연결되지 않는 정점은 방문하지 않는다는걸 생각해야됨
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (adj[i][j] && !visit[i]) {
				dfs(i);
			}
		}

	}
	return 0;
}
