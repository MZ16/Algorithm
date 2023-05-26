#include <bits/stdc++.h>
using namespace std;

// input <= 60

int N;
int visited[62][62][62];
int arr[3];
int _arr[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,1,9},
	{3,9,1},
	{1,9,3},
	{1,3,9}
};
struct Tuple
{
	int a,b,c;
};
queue<Tuple> q;

void bfs(int a, int b, int c) {
	visited[a][b][c] = 1;
	q.push({ a,b,c });
	while (!q.empty()) {
		int ha = q.front().a;
		int hb = q.front().b;
		int hc = q.front().c;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int na = max(0, ha - _arr[i][0]); // max 0 �� ������ �����ϱ� ����
			int nb = max(0, hb - _arr[i][1]);
			int nc = max(0, hc - _arr[i][2]);
			if (visited[na][nb][nc])continue; // �湮�� ���� ó��
			visited[na][nb][nc] = visited[ha][hb][hc] + 1;
			q.push({ na,nb,nc });
		}
	}
	cout << visited[0][0][0] - 1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> arr[i];
	bfs(arr[0], arr[1], arr[2]);
	return 0;
}

/* map�� ��ǥ, ����ġ bfs������ �ƴ� ������ �������� �̷���� bfs�����̴�.
* �־��� ���� ����� �� = map�� �����¿�
* if-continue / �湮�� ���� ó�� �� ���� ���� depth�� ans�� ����
*/