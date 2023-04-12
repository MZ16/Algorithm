#include <bits/stdc++.h>
using namespace std;

// x,y <=100

int arr[103][103];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[103][103];
vector<pair<int, int>> v; // 치즈 좌표
int N, M, cnt1, cnt2; // cnt1 - 녹는 시간, cnt2 - 마지막 치즈 개수

void dfs(int y, int x) {
	visited[y][x] = 1;
	if (arr[y][x]) {
		v.push_back({ y,x });
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<0 || ny>N || nx<0 || nx>M || visited[ny][nx])continue;
		dfs(ny, nx);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	while (1) {
		memset(visited, 0, sizeof(visited));
		cnt2 = 0;
		dfs(0, 0);
		for (auto i : v) { // 외곽 치즈 초기화 및 개수 카운팅
			cnt2++;
			arr[i.first][i.second] = 0;
		}
		for (auto i : v)v.pop_back();
		bool flag = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (arr[i][j])flag = 1; // 치즈 여부 확인
		cnt1++;
		if (!flag)break;
	}
	cout << cnt1 << "\n" << cnt2;
	return 0;
}

/* dfs 한번순회 시 외곽의치즈가 한칸씩 녹아내리는 문제이므로 치즈개수와 visited는 한번순회마다 초기화 해준다.
* 1. dfs가 조금 변형된다. 외곽의 치즈의 좌표를 구하기위해 해당위치가 치즈일 경우 좌표값을 저장하고 return, 아니라면 dfs진행
* 2. 치즈가 녹는 시간과 마지막단계에서 치즈개수를 표기하기 위해 카운트변수 2개가 필요
* 3. 치즈가 모두 녹아내렸음을 판단하는 flag가 필요하다. / 시작 시 초기화를 함으로 끝에서 flag여부에 따라 무한루프를 탈출한다.
*/