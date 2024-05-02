#include <bits/stdc++.h>
using namespace std;

int userMap[5][5];
int visited[5][5];
int moderatorMap[5][5];
int x, y;
// ��ȸ�ڰ� ���ڸ� �θ��� ������ ��ü�� Ž���ؼ� �ش� ���ڸ� üũ

int check() { // ���� Ȯ�� ���� ���� �밢��
	int chk1 = 1, chk2 = 1;
	int bingo = 0;
	
	for (int i = 0; i < 5; i++) { // ����
		for (int j = 0; j < 5; j++) {
			if (visited[i][j] != 1)chk1 = 0;
			if (visited[j][i] != 1)chk2 = 0;
		}if (chk1)bingo++;
		if (chk2)bingo++;
		chk1 = chk2 = 1;
	}
	int cnt = 4;
	if (visited[0][0] == 1 && visited[1][1] == 1 && visited[2][2] && visited[3][3] == 1 && visited[4][4] == 1)bingo++;
	if (visited[4][0] == 1 && visited[3][1] == 1 && visited[2][2] && visited[1][3] == 1 && visited[0][4] == 1)bingo++;
	return bingo;
}

void Comp(int val) { // ��ȸ�ڰ� �θ� ���� Ȯ��
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (userMap[i][j] == val) {
				visited[i][j] = 1;
				return;
			}
		}
	}
	return;
}

void Input() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> userMap[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> moderatorMap[i][j];
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			++cnt;
			Comp(moderatorMap[i][j]);
			if (check()>=3) {
				cout << cnt;
				return 0;
			}
		}
	}
	return 0;
}
