#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX_LEN 129
using namespace std;

bool visited[MAX_LEN][MAX_LEN];
int map[MAX_LEN][MAX_LEN];
int white, blue;
int N;

void dfs(int y, int x, int size) {
	visited[y][x] = 1;
	bool One=true, Zero=true;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (map[i][j] == 0)One = false;
			else if (map[i][j] == 1)Zero = false;

		}
	}
	if (One) {
		blue++;
		return;
	}
	if (Zero) {
		white++;
		return;
	}
	dfs(y, x, size / 2);
	dfs(y, x+size/2, size / 2);
	dfs(y+size/2, x, size / 2);
	dfs(y+size/2, x+size/2, size / 2);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0, 0, N);
	printf("%d\n", white);
	printf("%d", blue);
	return 0;
}