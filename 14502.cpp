#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int arr[9][9];
int visited[9][9];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
vector<pii>v; // '0'ÀÇ À§Ä¡ÁÂÇ¥
int N, M;

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] == 1 || arr[ny][nx] != 0)continue;
		dfs(ny, nx);
	}
	return;
}

int ans() {
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 2)dfs(i, j);
		}
	}
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && arr[i][j] == 0)ret++;
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)v.push_back({ i,j });
		}

	int ret = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				arr[v[i].first][v[i].second] = arr[v[j].first][v[j].second] = arr[v[k].first][v[k].second] = 1;
				ret = max(ret, ans());
				arr[v[i].first][v[i].second] = arr[v[j].first][v[j].second] = arr[v[k].first][v[k].second] = 0;
			}
		}
	}
	cout << ret;
	return 0;
}