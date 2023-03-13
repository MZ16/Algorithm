#include <bits/stdc++.h>
using namespace std;

// M,N,K <= 100
int M, N, K;
int visited[102][102];
int adj[102][102];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int cnt=1,ret;
vector<int>v;
void dfs(int y, int x) {
	visited[y][x] = 1;	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny>=M || nx<0 || nx>=N)continue;
		if (!visited[ny][nx]&&!adj[ny][nx]) {
			cnt++;			
			dfs(ny, nx);
		}
	}

	return;
}

int main() {
	cin >> M >> N >> K;
	for (int t = 0; t < K; t++) {
		int x1, y1, x2, y2;
		// 1 - 왼쪽 밑(x1,y1), 2 - 오른쪽 위(x2,y2)
		cin >> x1 >> y1 >> x2 >> y2;
		
		// x1,y1부터 시작하여 x2,y2까지 모두 채움
		for (int i = y1; i < y2; i++) { 
			for (int j = x1; j < x2; j++) {
				adj[i][j]++;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			//cout << adj[i][j] << " ";
			if (!visited[i][j] && !adj[i][j]) {
				ret++; dfs(i, j);
				//cout << cnt << "\n";
				v.push_back(cnt);
				cnt = 1;
			}
		}
		//cout << "\n";
	}
	sort(v.begin(), v.end());
	cout << ret<<"\n";
	for (auto i : v) cout << i<<" ";
	return 0;
}