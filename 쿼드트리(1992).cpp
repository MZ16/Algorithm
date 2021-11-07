#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAX_SIZE 64

int arr[MAX_SIZE][MAX_SIZE];

void dfs(int x, int y, int size) {
	if (size == 1) {
		cout << arr[x][y];
		return;
	}
	bool Zero = true, One = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] == 0) One = false;
			else if (arr[i][j] == 1) Zero = false;
		}
	}
	if (One) {
		cout << 1;
		return;
	}
	else if (Zero) {
		cout << 0;
		return;
	}
	cout << '(';
	dfs(x, y, size / 2);
	dfs(x, y + size / 2, size / 2);
	dfs(x+size/2, y, size / 2);	
	dfs(x + size / 2, y + size / 2, size / 2);
	cout << ')';
}

int main() {
	int N;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	dfs(0, 0, N);

	return 0;
}
