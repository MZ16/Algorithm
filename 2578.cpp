#include <bits/stdc++.h>
using namespace std;

int userMap[5][5];
int visited[5][5];
int moderatorMap[5][5];
int x, y;
// 사회자가 숫자를 부르면 유저는 전체를 탐색해서 해당 숫자를 체크

int check() { // 빙고 확인 가로 세로 대각선
	int chk1 = 1, chk2 = 1;
	int bingo = 0;
	
	for (int i = 0; i < 5; i++) { // 가로
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

void Comp(int val) { // 사회자가 부른 숫자 확인
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
