#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[12][12], arr[12][12];
int ans = INF, N;


bool check(int y, int x) {
	if (visited[y][x])return 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx])return 0;
	}
	return 1;
}

int flower_cost(int y, int x) {
	visited[y][x] = 1;
	int sum = arr[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		sum += arr[ny][nx];
		visited[ny][nx] = 1;
	}
	return sum;
}

void eraseFlower(int y, int x) {
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 0;		
	}
	return;
}

void flower(int cnt, int sum) {
	if (cnt == 3) {
		ans = min(ans, sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {			
			if (check(i, j)) {
				flower(cnt + 1, sum + flower_cost(i, j));
				eraseFlower(i, j);
			}
			
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	flower(0, 0);
	cout << ans;

	return 0;
}

/* 
*	배열범위 10*10, 꽃의 개수 3개이므로 100 C 3, 100!-(100-3)! / 3!로 약 시간복잡도는 약 16만으로 완전탐색으로 접근가능하다.
*	1. 현 위치에 꽃을 놓을 수 있는가? 를 판단하는 bool 함수
*	2. 현 위치에 꽃이 있다면 cost를 합한 후 반환해주는 함수
*	3. backtracking을 위해 현재 위치의 꽃을 삭제하는 함수
		꽃이 3개여서 MIN값을 구하고 반환됬거나, 탐색이 끝났는데 3개가 아닐 경우
*	4. 모듈화 한 1,2,3번을 통해 bool 체크, cost, backtracking, MIN값 등을 구하는 재귀함수

* 실수한 부분
	전체적으로 생각한 로직들은 다 들어가는데 모듈화를 잘 못해 풀지 못한 문제이다.
*/