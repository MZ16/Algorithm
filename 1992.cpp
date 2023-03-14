#include <bits/stdc++.h>
using namespace std;

// 분할정복
// 1 <= N <= 64
// N*N배열을 탐색하며 가장 왼쪽 위의 수와 다른 수가 나오면 (N/2)*(N/2)크기로 4등분하여 재귀함수 호출
// 호출 전 후로 '(' , ')'를 처리해준다.

string s[64];
int N;

void quard(int y, int x, int size) {
	char cur = s[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (cur != s[i][j]) {
				cout << '(';
				quard(y, x, size / 2); // 1사분면
				quard(y, x + size / 2, size / 2); // 2사분면
				quard(y + size / 2, x, size / 2); // 3사분면
				quard(y + size / 2, x + size / 2, size / 2); // 4사분면
				cout << ')';
				return; // 분할정복 후 return
			}
		}
	}cout << cur; // 현재 사이즈 전체가 cur로 구성됨
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> s[i];
	quard(0, 0, N);

	return 0;
}