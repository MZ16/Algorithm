#include <iostream>
#include <algorithm>
using namespace std;

bool visited[9];
int arr[9];
int N, M;

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}cout << "\n";
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i])continue;
		visited[i] = true;
		arr[depth] = i;
		dfs(depth + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> N >> M;
	dfs(0);

	return 0;
}
