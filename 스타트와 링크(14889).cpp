#include <iostream>
#include <algorithm>
using namespace std;


bool visit[22];
int arr[21][21];
int ans = 987654321;
int N;

void dfs(int depth, int pos) {
	if (depth == N/2) {
		int start = 0, link = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visit[i] && visit[j]) start += arr[i][j];
				if (visit[i] == false && visit[j] == false) link += arr[i][j];
			}
		}
		int min = abs(start - link);
		ans = ans < min ? ans : min;
		return;
	}
	for (int i = pos; i <= N; i++) {
		visit[i] = true;
		dfs(depth + 1, i + 1);
		visit[i] = false;
	}
	
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	dfs(0, 1);
	cout << ans;
}