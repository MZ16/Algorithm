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
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])continue; // ���ӵ� ������
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

/*	���μ�-N, ���μ�-H, �־��� ���μ�-M
*	2 <= N <= 10, 1 <= H <= 30, 0 <= M <= (N-1)*H �̸� �ð����⵵�� 300 C 10�̴�.
*	�̷� ��� ��Ž���� ������ �� ���� ���������� ���� ���ǿ��� �߰��Ǵ� �������� ������
*	3�� �ʰ��̰ų� �Ұ����ϸ� -1�� ����϶�� ������ �ֱ� ������ 300 C 3 ����
*	�� 450���� �ð����⵵�� ���� ��Ʈ��ŷ���� �����ؾ� �Ѵ�.
* 
*	2���� �湮�迭�� ���� �ִٸ� ���� �ε����� �����ٷ� ����Ǵ� �������� �ִ� ��� ���·� ����
*	ex) visited[2][1] = 1��° �������� 2���� depth���� ����idx�� �������� 2��° �����ٷ� ����Ǵ� �������� �����Ѵ�.
* 
*	1. i�� �������� ����� i���� ������ check �Լ��� ����
*	2. ��Ž�� ���� ����Լ� ����
*		backtracking, check �Լ��� ���� �߰��� �������� �ּ� ����, ���ӵ� �������� �Ǵ� �� ������ �߰� �� ��Ž
* 
*/