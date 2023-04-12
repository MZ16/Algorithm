#include <bits/stdc++.h>
using namespace std;

// x,y <=100

int arr[103][103];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int visited[103][103];
vector<pair<int, int>> v; // ġ�� ��ǥ
int N, M, cnt1, cnt2; // cnt1 - ��� �ð�, cnt2 - ������ ġ�� ����

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
		for (auto i : v) { // �ܰ� ġ�� �ʱ�ȭ �� ���� ī����
			cnt2++;
			arr[i.first][i.second] = 0;
		}
		for (auto i : v)v.pop_back();
		bool flag = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (arr[i][j])flag = 1; // ġ�� ���� Ȯ��
		cnt1++;
		if (!flag)break;
	}
	cout << cnt1 << "\n" << cnt2;
	return 0;
}

/* dfs �ѹ���ȸ �� �ܰ���ġ� ��ĭ�� ��Ƴ����� �����̹Ƿ� ġ����� visited�� �ѹ���ȸ���� �ʱ�ȭ ���ش�.
* 1. dfs�� ���� �����ȴ�. �ܰ��� ġ���� ��ǥ�� ���ϱ����� �ش���ġ�� ġ���� ��� ��ǥ���� �����ϰ� return, �ƴ϶�� dfs����
* 2. ġ� ��� �ð��� �������ܰ迡�� ġ����� ǥ���ϱ� ���� ī��Ʈ���� 2���� �ʿ�
* 3. ġ� ��� ��Ƴ������� �Ǵ��ϴ� flag�� �ʿ��ϴ�. / ���� �� �ʱ�ȭ�� ������ ������ flag���ο� ���� ���ѷ����� Ż���Ѵ�.
*/