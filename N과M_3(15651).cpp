#include <iostream>
#include <algorithm>
using namespace std;

bool visited[9];
int arr[9];
int N, M, idx = 1;

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[depth] = i;
		dfs(depth + 1);
	}
}

int main() {
	cin >> N >> M;
	dfs(0);

	return 0;
}
