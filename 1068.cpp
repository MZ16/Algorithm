#include <bits/stdc++.h>
using namespace std;

// N <= 50

vector<int> adj[52];
int N,M, root;

int dfs(int here) {
	int child = 0;
	int ret = 0;
	for (int there : adj[here]) {
		if (there == M)continue;
		ret += dfs(there);
		child++; // ������� �ľ��� ����
	}
	if (!child)return 1;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp == -1)root = i; // root��� (0)
		else adj[tmp].push_back(i);
	}
	cin >> M;
	if (M == root)cout << 0;
	else cout << dfs(root);
	return 0;
}



/* dfs�� ��ȸ�ϵ� ���� ���� ��ȸ���� ������ ��
* - ��������Ʈ ���·� Ʈ���� ����
* - for-each�� ���� ���� �������, dfs��ȸ, �ڽĳ�尡 ���θ� Ȯ���Ѵ�.
*		: for-each�� ����ϸ� ���� ����� ��� �ش� �ε����� ����� ���� ���� ������� �ʴ´�.
* - child���� 0�̶�� ��������̹Ƿ� ���� ��� ���� ������ ���� 1�� ��ȯ ���ش�.
* - child���� �ִ� ��� ret�� ��ȯ���ش�.
*/