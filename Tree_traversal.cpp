#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool visited[101];

// ������ȸ�� �� ������ Ž���̸� root������ �����Ͽ� �θ� - ���� �ڽ� - ������ �ڽ� ���̴�.
// ���� : ������ (DFS) - V, LF, RF ��
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

// ������ȸ�� �� ������ Ž���̸� ���� �ڽ� - �θ� - ������ �ڽ� ��� ���̴�.
// ���� : LF, V, RF ��
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

// ������ȸ�� �� ������ Ž���̸� ���� �ڽ� - ������ �ڽ� - �θ� ��� ���̴�.
// ���� : �ڽĵ���� - LF, RF, V ��
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
// level ��ȸ�� bfs�̴�.

int main() {
	adj[1].push_back(2); adj[1].push_back(3);
	adj[2].push_back(4); adj[2].push_back(5);

	cout << "\n���� ��ȸ\n";
	PreOrder(1); memset(visited, 0, sizeof(visited)); // visit �ʱ�ȭ
	cout << "\n���� ��ȸ\n";
	InOrder(1); memset(visited, 0, sizeof(visited)); // visit �ʱ�ȭ
	cout << "\n���� ��ȸ\n";
	PostOrder(1); memset(visited, 0, sizeof(visited)); // visit �ʱ�ȭ

	return 0;
}