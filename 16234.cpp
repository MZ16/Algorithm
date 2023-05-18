#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii>v; // 평균 갱신 좌표
int arr[54][54];
int N, L, R;
int visited[54][54];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int ans,flag=1;

void bfs(int y, int x) {
	queue<pii> q;
	int pCnt = arr[y][x]; // 연합인원
	visited[y][x] = 1;
	q.push({ y,x });
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];			
			if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx])continue;
			int tmp = abs(arr[y][x] - arr[ny][nx]);
			if (tmp >= L && tmp <= R) {
				flag = 1; // 연합 여부를 판단
				visited[ny][nx] = 1;
				pCnt += arr[ny][nx];
				q.push({ ny,nx });
				v.push_back({ ny,nx });
			}
		}		
	}

	// 연합 인구 갱신
	if(v.size()>=2)
		for (int i = 0; i < v.size(); i++) arr[v[i].first][v[i].second] = pCnt / v.size();

		
	
	
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	while (flag) {
		flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					v.clear();
					v.push_back({ i,j }); // 초기값
					bfs(i, j);					
				}

				/*for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						cout << arr[i][j] << " ";
					}cout << "\n";
				}cout << "\n";*/
			}

		}
		if (flag)ans++;
		memset(visited, 0, sizeof(visited));
		
	}
	
	cout << ans;
	return 0;
}
/*
* 
1. 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
2. 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
3. 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
4. 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
5. 연합을 해체하고, 모든 국경선을 닫는다.
*/

/* 오답
- flag의 사용이 잘못됨, 주어진 배열 전체를 한싸이클을 돌아야하는데 한 좌표의 bfs로만 flag를 판단하고 ans값을 증가시켜줌

- 문제를 잘못 이해함, 한 정점의 bfs로 값의 갱신이 일어나면 다음 정점에서도 visit을 초기화 한 후 
	갱신된 값으로 다시 값을 갱신하는 줄 알고 작성함

- 방문한 정점은 다시 방문하지 않으며 배열 전체를 bfs한 다음 day를 증가시킨다.
- 한 싸이클이 끝나면 방문배열을 초기화한다.
*/