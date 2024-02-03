#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int ans = INF;
int N, M, H;
int visited[33][33];

bool check() {
	for (int i = 1; i <= N; i++) {
		int start = i;
		for (int j = 1; j <= H; j++) {
			if (visited[j][start])start++;
			else if (visited[j][start - 1])start--;
		}
		if (start != i)return false;
	}
	return true;
}

void func(int idx, int cnt) {
	if (cnt > 3 || cnt > ans)return; //
	if (check()) {
		ans = min(ans, cnt);
		return;
	}
	for (int i = idx; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])continue; // 연속된 가로줄
			visited[i][j] = 1;
			func(i, cnt+1);
			visited[i][j] = 0;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
	}
	func(1, 0);
	if (ans != INF)cout << ans;
	else cout << -1;

	return 0;
}

/*	세로선-N, 가로선-H, 주어진 가로선-M
*	2 <= N <= 10, 1 <= H <= 30, 0 <= M <= (N-1)*H 이며 시간복잡도는 300 C 10이다.
*	이럴 경우 완탐으론 접근할 수 없는 범위이지만 문제 조건에서 추가되는 가로줄의 개수는
*	3개 초과이거나 불가능하면 -1을 출력하라는 지문이 있기 때문에 300 C 3 으로
*	약 450만의 시간복잡도를 가져 백트레킹으로 접근해야 한다.
* 
*	2차원 방문배열의 값이 있다면 다음 인덱스의 세로줄로 연결되는 가로줄이 있다 라는 형태로 구현
*	ex) visited[2][1] = 1번째 세로줄의 2번쨰 depth에서 다음idx의 세로줄인 2번째 세로줄로 연결되는 가로줄이 존재한다.
* 
*	1. i번 세로줄의 결과가 i번이 나오는 check 함수를 구현
*	2. 완탐을 위한 재귀함수 구현
*		backtracking, check 함수를 통한 추가된 가로줄의 최소 개수, 연속된 가로줄을 판단 후 가로줄 추가 및 완탐
* 
*/