#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool visited[101];

// 전위순회는 ∠ 형태의 탐색이며 root노드부터 시작하여 부모 - 왼쪽 자식 - 오른쪽 자식 순이다.
// 전위 : 나부터 (DFS) - V, LF, RF 순
void PreOrder(int here) {
	if (!visited[here]) {
		visited[here] = true;
		cout << here << " ";
		if (adj[here].size() == 1)PreOrder(adj[here][0]);
		if (adj[here].size() == 2) {
			PreOrder(adj[here][0]);
			PreOrder(adj[here][1]);
		}
	}
	return;
}

// 중위순회는 ∧ 형태의 탐색이며 왼쪽 자식 - 부모 - 오른쪽 자식 노드 순이다.
// 중위 : LF, V, RF 순
void InOrder(int here) {
	if (!visited[here]) {
		if (adj[here].size() == 1) {
			InOrder(adj[here][0]);
			visited[here] = true;
			cout << here << " ";
		}
		if (adj[here].size() == 2) {
			InOrder(adj[here][0]);
			visited[here] = true;
			cout << here << " ";
			InOrder(adj[here][1]);			
		}
		if (!adj[here].size()) {
			visited[here] = true;
			cout << here << " ";
		}
	}
	return;
}

// 후위순회는 ＞ 형태의 탐색이며 왼쪽 자식 - 오른쪽 자식 - 부모 노드 순이다.
// 후위 : 자식들부터 - LF, RF, V 순
void PostOrder(int here) {
	if (!visited[here]) {
		if (adj[here].size() == 1)PostOrder(adj[here][0]);
		if (adj[here].size() == 2) {
			PostOrder(adj[here][0]);
			PostOrder(adj[here][1]);
		}
		visited[here] = true;
		cout << here << " ";
	}
	return;
}
// level 순회는 bfs이다.

int main() {
	adj[1].push_back(2); adj[1].push_back(3);
	adj[2].push_back(4); adj[2].push_back(5);

	cout << "\n전위 순회\n";
	PreOrder(1); memset(visited, 0, sizeof(visited)); // visit 초기화
	cout << "\n중위 순회\n";
	InOrder(1); memset(visited, 0, sizeof(visited)); // visit 초기화
	cout << "\n후위 순회\n";
	PostOrder(1); memset(visited, 0, sizeof(visited)); // visit 초기화

	return 0;
}