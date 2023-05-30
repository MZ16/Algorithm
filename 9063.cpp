#include <bits/stdc++.h>
using namespace std;

int N, ans;
int col[15];

int chk(int depth) {
	for (int i = 0; i < depth; i++)
		if (col[depth] == col[i] || abs(col[depth] - col[i]) == depth - i) return 0;
	return 1;
}

void go(int depth) {
	if (depth == N)ans++;
	else {
		for (int i = 0; i < N; i++) {
			col[depth] = i;
			if (chk(depth))
				go(depth+1);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	go(0);
	cout << ans;


	return 0;
}


/* 각 행에서 유효성 검사를 진행 후 가능하다면 다음 depth로 재귀
*	1. 대각선 = 두 말의 +-depth값이므로 절댓값으로 처리해준다 / abs(col[depth]-col[i]) == depth-i
*	2. 같은열 - 두 행렬의 값이 같으면 같은열이다 / col[depth] == col[i]
*	위 조건은 성립하면 말을 둘 수 없다.
* 유효한 말이 N개가 아니라면 돌아와서 해당 depth의 다음 열값을 진행한다.
*/