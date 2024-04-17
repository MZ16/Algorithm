#include <bits/stdc++.h>
using namespace std;

pair<int, int> melonField[12];

int main() {
	int MAX_area = 0, MIN_area = 1e9;
	int N;

	cin >> N;
	for (int i = 0; i < 6; i++) {
		int x, y;
		cin >> x >> y;
		melonField[i] = melonField[i + 6] = { x,y };
	}

	for (int i = 3; i < 12; i++) {
		if (melonField[i].first == melonField[i - 2].first && melonField[i - 1].first == melonField[i - 3].first) {
			MAX_area = melonField[i + 1].second * melonField[i + 2].second;
			MIN_area = melonField[i - 1].second * melonField[i - 2].second;
			break;
		}
	}
	cout << N * (MAX_area - MIN_area);

	return 0;
}

/*
���� �����ߴ� Ʋ�� �����̴�.
�Է� ������ �ݽð�������� ���� ������ 13, 41, 24, 32 �� �ϳ���.
���� �簢���� ���̸� ã���� ū �簢���� ���̵� �ٷ� ã�� �� �ִ�.
*/