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
*	�迭���� 10*10, ���� ���� 3���̹Ƿ� 100 C 3, 100!-(100-3)! / 3!�� �� �ð����⵵�� �� 16������ ����Ž������ ���ٰ����ϴ�.
*	1. �� ��ġ�� ���� ���� �� �ִ°�? �� �Ǵ��ϴ� bool �Լ�
*	2. �� ��ġ�� ���� �ִٸ� cost�� ���� �� ��ȯ���ִ� �Լ�
*	3. backtracking�� ���� ���� ��ġ�� ���� �����ϴ� �Լ�
		���� 3������ MIN���� ���ϰ� ��ȯ��ų�, Ž���� �����µ� 3���� �ƴ� ���
*	4. ���ȭ �� 1,2,3���� ���� bool üũ, cost, backtracking, MIN�� ���� ���ϴ� ����Լ�

* �Ǽ��� �κ�
	��ü������ ������ �������� �� ���µ� ���ȭ�� �� ���� Ǯ�� ���� �����̴�.
*/