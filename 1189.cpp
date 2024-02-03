#include <bits/stdc++.h>
using namespace std;

int R, C, K;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[7][7];
string arr[7];
int ans;


void dfs(int y, int x) {
	if (y == 0 && x == C - 1 && visited[y][x]==K) {
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] || arr[ny][nx] == 'T')continue;
		visited[ny][nx] = visited[y][x] + 1;
		dfs(ny, nx);
		visited[ny][nx] = 0;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}
	visited[R - 1][0] = 1;
	dfs(R-1, 0);
	cout << ans;
	return 0;
}

/*  ��Ž�ϱ⿡ �������� �ð����⵵�̸� ��Ʈ��ŷ �����̴�.
*	dfs�� ����Ž���� �Ѵ�.
*	������ �湮�迭 ����ġ�� K�� ���ٸ� ī��Ʈ�� ������Ű�� ��ȯ�Ѵ�.
*	���� ��� Ȥ�� �� �̻� Ž���� �Ұ����ϴٸ� ��Ʈ��ŷ
* 
�Ǽ��� �κ�
	���� ���� �� T�� ��ġ�� �������� �� �� ���ٶ� ���� ���µ� ������� ������ (������ ���������� �������� ����)
	�������� ���� �Ʒ� �������� ������ ����� ��� �������� �������� 0,0���� ��������
*/