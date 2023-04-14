#include <bits/stdc++.h>
using namespace std;

// N <= 10,000 , M <= 100,000 dfs ©ое╫ ╫ц O(N^2) = 1╬О
int visited[10001];
vector<int> adj[10001];
int N, M;
int result, dp[10001];
int dfs(int here) {
	int ret = 1;
	visited[here] = 1;
	for (int i : adj[here]) {
		if (visited[i])continue;		
		ret += dfs(i);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		adj[tmp2].push_back(tmp1);
	}

	for (int i = 0; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		dp[i] = dfs(i);
		result = max(dp[i], result);
	}

	for (int i = 0; i <= N; i++) 
		if (result == dp[i])cout << i << " ";
	

	return 0;
}
