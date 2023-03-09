#include <bits/stdc++.h>
using namespace std;

// 1. 0~9까지의 정점, 1-2 / 1-3 / 3-4 의 간선
// 0번부터 방문안한 노드를 찾고 연결된 노드를 이어서 방문하여 출력하는 재귀함수, 방문한 정점은 다시 방문하지 않는다.

const int V = 10;
vector <int> adj[V];
bool visited[V];
 
void dfs(int i) {
	visited[i] = true;
	cout << "정점 : "<<i<<"\n";
	for (int there : adj[i]) {
		if (visited[there]) continue;
		cout << "간선 : "<<i<<"-"<<there<<"\n";
		dfs(there);
	}
	return;
}

int main() {
	adj[1].push_back(2); adj[1].push_back(3); adj[2].push_back(1);	
	adj[3].push_back(1); adj[3].push_back(4); adj[4].push_back(3);

	for (int i = 0; i < V; i++) {
		if (visited[i])continue;
		else if(!visited[i] && adj[i].size())dfs(i);
	}
	


	return 0;
}
