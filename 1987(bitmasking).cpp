#include <bits/stdc++.h>
using namespace std;

int R, C, ans;
char a[22][22];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void go(int y, int x, int num, int cnt) {
	ans = max(ans, cnt); // 최대경로 갱신
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)continue;
		int next = (1 << (int)a[ny][nx] - 'A'); // 다음 위치의 bit
		// num은 현재까지 경로상에 있던 알파벳의 bit의 합, next는 다음 위치의 bit
		if (!(num & next)) go(ny, nx, num | next, cnt + 1); // 다음 위치좌표와 bit 합연산
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
		}
	}
	// 출발점의 알파벳을 비트로 바꿔서 인자를 전달함
	go(0, 0, (1 << (int)a[0][0] - 'A'), 1);
	cout << ans;
	return 0;
}