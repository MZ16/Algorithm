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
쉽게 접근했다 틀린 문제이다.
입력 순서는 반시계방향으로 돌기 떄문에 13, 41, 24, 32 중 하나다.
작은 사각형의 길이를 찾으면 큰 사각형의 길이도 바로 찾을 수 있다.
*/