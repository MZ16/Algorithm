#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int arr[9][9];
int visited[9][9];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
vector<pii>v; // '0'의 위치좌표
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

/*dfs 
	1. 기둥 세우기 - nCr, n! / r(n-r)!
		- 입력 받을 때 기둥을 세울 수 있는 '0'의 위치를 pair vector에 저장
		- 배열에 pair vector를 이용하여 기둥을 세운다('1'로 변경)
		- 안전 영역의 MAX값을 갱신한다.
		- '1'로 변경된 값을 '0'으로 초기화한다. (MAX값을 계속 갱신하기 위함)

	2. 바이러스 퍼트리기
		- 기둥을 세울 때 마다 실행하므로 visited를 '0'으로 초기화 한다
		- 배열을 순회하며 '2'인 경우 dfs
		- dfs가 끝난 후 방문하지 않을 배열을 카운팅 후 카운팅값을 return 한다. 
*/