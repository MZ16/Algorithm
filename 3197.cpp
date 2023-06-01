#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 1502;
int R, C, y, x, ans, swanY, swanX;
char arr[MAX][MAX];
int visited_water[MAX][MAX], visited_swan[MAX][MAX];
queue<pii>waterQ, water_tmpQ, swanQ, swan_tmpQ;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void Qclear(queue<pii>& q) { // while q.pop���� ����� q���� swap�� �� ������.
	queue<pii>empty;
	swap(q, empty);
	return;
}

void water_melting() {
	while (!waterQ.empty()) {
		tie(y, x) = waterQ.front();
		waterQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited_water[ny][nx])continue;
			if (arr[ny][nx] == 'X') {
				visited_water[ny][nx] = 1;
				water_tmpQ.push({ ny,nx }); // water�� ���� ��ǥ ����
				arr[ny][nx] = '.';
			}
		}
	}
}

int move_swan() {
	while (!swanQ.empty()) {
		tie(y, x) = swanQ.front();
		swanQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])continue;
			visited_swan[ny][nx] = 1;
			if (arr[ny][nx] == '.') { swanQ.push({ ny,nx }); }
			else if (arr[ny][nx] == 'X') { swan_tmpQ.push({ ny,nx }); } // swan�� ������ǥ ����
			else if (arr[ny][nx] == 'L')return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			// �Ʒ� ó�� ���� �� L�� �ΰ��̹Ƿ� ������ �����.
			//if (arr[i][j] == 'L') { visited_swan[i][j] = 1; swanQ.push({ i,j }); } 
			if (arr[i][j] == 'L') { swanY = i; swanX = j; }
			if (arr[i][j] == '.' || arr[i][j] == 'L') { visited_water[i][j] = 1; waterQ.push({ i,j }); } // �� �ʱⰪ ����(������ �� ��������)
		}
	}
	visited_swan[swanY][swanX] = 1; swanQ.push({ swanY,swanX }); // ���� �ʱⰪ ����
	while (1) {
		if (move_swan())break; // true��ȯ �� ������ ����
		water_melting();
		swanQ = swan_tmpQ; // �����ص� ������ ���� �ʱⰪ
		waterQ = water_tmpQ; // �����ص� ���� �ʱⰪ(���ϰ� ��������)
		Qclear(swan_tmpQ);
		Qclear(water_tmpQ);
		ans++;
	}
	cout << ans;
	return 0;
}



/* flood fill (qSize�� �ƴ� temp�� ���� �Ѵ� �̰��� ����)
* �ʱⰪ ������ ���� �Է¹����鼭 '.'�� 'L'�� ��ǥ�� �����Ѵ�.
* water_melting()
*	���� �ʱ���ǥ�� ��� visited�����̸� �ش�q(waterQ)�� �ʱⰪ�� ��� ���ִ�.
*	�� ���� X��ǥ�� üũ �� �湮ó�� �� X�� '.'���� �ٲ۴�.
* move_swan()
*	������ �ʱ���ǥ�� visited�����̸� �ش� q(swanQ)�� �ʱ���ǥ���� ����ִ�
*	'.'�� ���� �ش� q(swanQ) push�� ���� ��� �̵����� �ϰ� ��
*	'X'�� ��� ������ ���� �ʱ� ��ǥ���̹Ƿ� ���ҿ� q(swan_tmpQ)�� ������ �д�.
*		�ٸ� q�� �����Ͽ����Ƿ� bfs�� ���ѷ����� ���´�.
*	'L'�� ��� �ٸ� ������ �������̹Ƿ� return true;�� ���ش�.
* 
* �ش� �������� �������� ���� ���� ������ ���ѷ����� ���������� �����Ͽ� ������ ���� �ݺ��Ѵ�.
*/