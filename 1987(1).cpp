#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int R,C,ans=1,cnt;
int visited[21][21];
int Alpabet[26];
char arr[21][21];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void dfs(int y, int x) {
	visited[y][x] = 1;
	Alpabet[arr[y][x] - 'A'] = 1;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || Alpabet[arr[ny][nx] - 'A'])continue;
		//visited[ny][nx] = 1; // dfs라 필요없을듯
		//Alpabet[arr[ny][nx] - 'A'] = 1; // 222
		cnt++;
		ans = max(ans, cnt);
		dfs(ny, nx);
		cnt--;
		visited[ny][nx] = 0;
		Alpabet[arr[ny][nx] - 'A'] = 0;
	}
	return;
}

int dfs2(int y, int x) { // backtracking 미적용 solution
	visited[y][x] = 1;
	Alpabet[arr[y][x] - 'A'] = 1;

	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || Alpabet[arr[ny][nx] - 'A'])continue;
		ret+=dfs2(ny, nx);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);
	cout << ans + 1; // backtracking
	//cout << dfs2(0,0); // backtrack X
	return 0;
}