#include <bits/stdc++.h>
using namespace std;

// �ʰ� ���⺤��

//	Q. 3 * 3 ���� �Է¹޾ƾ� ��.�� ���� 1�� 0���� �̷�����ְ�{ 0, 0 }�� ������ 1���� �����Ѵ�. {0, 0}���� 4������ �������� ��ĭ�� Ž���س����� 
//	�湮�� ������ �ٽ� �湮���� ������ �湮�ϴ� ��ǥ�� ����ϴ� �ڵ�. 0�� �� �� ���� ����. 1�� �� �� �ִ� ������ �����Ͻÿ�.


// �����¿� (��������� ��,��,��,�� ������ �ۼ��ϴ°��� ����.)
//int dy[4] = { 1,-1,0,0 };
//int dx[4] = { 0,0,-1,0 };

int visited[3][3]; int arr[3][3];

// �Ͽ����
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

// ��ǥ y,x
void go(int y, int x) {
	visited[y][x] = 1;
	cout << y << ":" << x << "\n";
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny>3 || nx < 0 || nx>3)continue; // map�� ���� �ʰ�
		if (arr[ny][nx] == 0) continue; // 0���� �̵��� �� ����
		if (visited[ny][nx]) continue;
		
		go(ny, nx);
	}
	return;
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	go(0, 0);

	

	return 0;
}