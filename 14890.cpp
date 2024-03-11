#include <bits/stdc++.h>
using namespace std;

int L, N, ans;
int a[102][102], b[102][102]; // 가로, 세로

void solve(int arr[102][102]) {
	for (int i = 0; i < N; i++) {
		int j,cnt=1;
		for (j = 0; j < N - 1; j++){ // j+1을 체크하기 위해 N-1
			if (arr[i][j] == arr[i][j + 1])cnt++; // 높이가 같음
			else if (cnt >= L && arr[i][j] + 1 == arr[i][j + 1])cnt = 1; // 오르막
			else if (cnt >= 0 && arr[i][j] - 1 == arr[i][j + 1])cnt = (-L + 1); // 내리막
			else break;
		}
		// 오르막과 내리막을 하나의 변수로 표현하기 위해 내리막을 음수로 갱신하였고
		// 현재 위치를 포함해야하니 1 또는 -L+1로 갱신했다.

		if (j+1 == N && cnt >= 0)ans++; // 끝까지 도달한 행또는 열의 조건
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			b[j][i] = a[i][j]; // 세로 배열을 가로로
		}
	}
	solve(a); solve(b);
	cout << ans;
	return 0;
}