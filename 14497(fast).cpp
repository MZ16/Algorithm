#include <bits/stdc++.h>
using namespace std;

const int MAX = 301;
char arr[MAX][MAX];
int visited[MAX][MAX];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int N, M;
int st1, st2, ed1, ed2;
int cnt;

void bfs() {
	visited[st1][st2] = 1;
	queue<int> q;
	q.push(st1*1000+st2);
	while (arr[ed1][ed2] != '0') {
		queue<int> tmp;
		cnt++;
		while (!q.empty()) {
			int y = q.front() / 1000;
			int x = q.front() % 1000;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])continue;
				visited[ny][nx] = 1;
				if (arr[ny][nx] != '0') {
					tmp.push(ny*1000+nx);
					arr[ny][nx] = '0';
					continue;
				}
				q.push(ny*1000+nx);
			}
		}
		q = tmp;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	cin >> st1 >> st2 >> ed1 >> ed2;
	st1--, st2--, ed1--, ed2--;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	bfs();
	cout << cnt;
	return 0;
}

/*
������ Ǯ�̴� ����Լ��� ���̰� ����� 80ms�� �������� flood fill�� ����ϸ� 4ms�� ���´�.

�ΰ��� ť�� ���
0�ϰ�� q(0), 0�� �ƴ϶��(1,#) tmpť�� ��� arr�� 0���� �ٲ��ش�.
ť�� ����������� �ݺ� �� �����ٸ� tmp���� q�� ����ش�.
*/