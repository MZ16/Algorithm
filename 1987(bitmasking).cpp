#include <bits/stdc++.h>
using namespace std;

int R, C, ans;
char a[22][22];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void go(int y, int x, int num, int cnt) {
	ans = max(ans, cnt); // �ִ��� ����
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)continue;
		int next = (1 << (int)a[ny][nx] - 'A'); // ���� ��ġ�� bit
		// num�� ������� ��λ� �ִ� ���ĺ��� bit�� ��, next�� ���� ��ġ�� bit
		if (!(num & next)) go(ny, nx, num | next, cnt + 1); // ���� ��ġ��ǥ�� bit �տ���
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
	// ������� ���ĺ��� ��Ʈ�� �ٲ㼭 ���ڸ� ������
	go(0, 0, (1 << (int)a[0][0] - 'A'), 1);
	cout << ans;
	return 0;
}