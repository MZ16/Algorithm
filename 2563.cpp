#include <bits/stdc++.h>
using namespace std;

int visited[100][100];
int ans;
int main() {
	int N;
	cin >> N;
	while (N--) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				if (visited[i][j])continue;
				visited[i][j] = 1;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

// map = 100
// 붙여지는 종이는 10*10사이즈, 한번 붙여진 자리를 check