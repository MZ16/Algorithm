#include <bits/stdc++.h>
using namespace std;

int N;
int arr[14];
int ans[6];

void dfs(int start, int depth) {
	if (depth == 6) {
		for (int i = 0; i < depth; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = start; i < N; i++) {
		ans[depth] = arr[i];
		dfs(i + 1, depth+1);
	}
	return;
}

int main() { 
	while (1) {
		cin >> N;
		if (N == 0)return 0;
		for (int i = 0; i < N; i++) cin >> arr[i];
		dfs(0, 0);
		cout << "\n";
		memset(arr, 0, sizeof(arr));
		memset(ans, 0, sizeof(ans));
	}

	return 0;
}