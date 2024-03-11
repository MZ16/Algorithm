#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 987654321;
int N, M, a[11], comp[11], visited[11], ans = INF;
vector<int> adj[11];

pii dfs(int here, int value) {
	visited[here] = 1;
	pii ret = { 1, a[here] }; 
	for (int there : adj[here]) {
		if (comp[there] != value)continue; // 연결되지 않은경우
		if (visited[there])continue;
		pii _tmp = dfs(there, value);
		ret.first += _tmp.first; // 지역의 합
		ret.second += _tmp.second; // 인구수 합
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];

	for (int i = 1; i <= N; i++) {
		cin >> M;
		for (int j = 1; j <= M; j++) {
			int tmp;
			cin >> tmp;
			adj[i].push_back(tmp);
			adj[tmp].push_back(i);
		}
	}

	for (int i = 1; i < (1 << N)-1; i++) {
		fill(visited, visited + 11, 0);
		fill(comp, comp + 11, 0);
		int idx1 = -1, idx2 = -1; // 각 구역의 시작점
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				comp[j + 1] = 1;
				idx1 = j + 1;
			}
			else idx2 = j + 1;
			
		}

		// 두 개의 구역으로 나누기
		pii comp1 = dfs(idx1, 1);
		pii comp2 = dfs(idx2, 0);

		// 두 개의 구역의 합이 N과 같을 경우만 최솟값 갱신
		if (comp1.first + comp2.first == N) {
			ans = min(ans, abs(comp1.second - comp2.second));
		}
	}
	cout << (ans == INF ? -1 : ans);
	return 0;
}

// 실수한 부분
// 39line, 두개의 구역은 각 각 최소 한개의 구역은 포함되어야 한다는 조건이 있기 때문에
// 비트의 최대 크기보다 한개 작은 값으로 조건을 주어야 한다.