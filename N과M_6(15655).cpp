#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int N, M;
int arr[9] = { 0, };
int arr2[9] = { 0, };
int idx = 0;
bool visit[9];
void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}cout << "\n";
		return;
	}
	for (int i = idx; i < N; i++)
	{
		if (visit[i]) continue;
		visit[i] = 1;
		arr[depth] = arr2[i];
		idx = i;
		dfs(depth + 1);
		visit[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		arr2[i] = arr[i];
	}
	sort(arr2, arr2 + N);
	dfs(0);

}