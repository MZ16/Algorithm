#include <bits/stdc++.h>
using namespace std;

// ��������
// 1 <= N <= 64
// N*N�迭�� Ž���ϸ� ���� ���� ���� ���� �ٸ� ���� ������ (N/2)*(N/2)ũ��� 4����Ͽ� ����Լ� ȣ��
// ȣ�� �� �ķ� '(' , ')'�� ó�����ش�.

string s[64];
int N;

void quard(int y, int x, int size) {
	char cur = s[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (cur != s[i][j]) {
				cout << '(';
				quard(y, x, size / 2); // 1��и�
				quard(y, x + size / 2, size / 2); // 2��и�
				quard(y + size / 2, x, size / 2); // 3��и�
				quard(y + size / 2, x + size / 2, size / 2); // 4��и�
				cout << ')';
				return; // �������� �� return
			}
		}
	}cout << cur; // ���� ������ ��ü�� cur�� ������
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> s[i];
	quard(0, 0, N);

	return 0;
}