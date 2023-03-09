#include <bits/stdc++.h>
using namespace std;

// 1. 0~9������ ����, 1-2 / 1-3 / 3-4 �� ����
// 0������ �湮���� ��带 ã�� ����� ��带 �̾ �湮�Ͽ� ����ϴ� ����Լ�, �湮�� ������ �ٽ� �湮���� �ʴ´�.

const int V = 10;
vector <int> adj[V];
bool visited[V];

void dfs(int i) {
	visited[i] = true;
	cout << "���� : "<<i<<"\n";
	for (int there : adj[i]) {
		if (visited[there]) continue;
		cout << "���� : "<<i<<"-"<<there<<"\n";
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