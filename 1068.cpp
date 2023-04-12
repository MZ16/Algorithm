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
		child++; // 리프노드 파악을 위함
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
		if (tmp == -1)root = i; // root노드 (0)
		else adj[tmp].push_back(i);
	}
	cin >> M;
	if (M == root)cout << 0;
	else cout << dfs(root);
	return 0;
}



/* dfs로 순회하되 지울 노드는 순회하지 않으면 됨
* - 인접리스트 형태로 트리를 구현
* - for-each를 통해 삭제 노드인지, dfs순회, 자식노드가 여부를 확인한다.
*		: for-each를 사용하면 리프 노드의 경우 해당 인덱스에 저장된 값이 없어 실행되지 않는다.
* - child값이 0이라면 리프노드이므로 리프 노드 갯수 증감을 위해 1을 반환 해준다.
* - child값이 있는 경우 ret을 반환해준다.
*/