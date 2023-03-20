#include <bits/stdc++.h>
using namespace std;

// 1 <= H,W <= 100 범위가 작아 반복문으로 해결
// (i,j) = c 일경우 check용 flag, ret, idx를 초기화시킴
// 'c'가 아니지만 flag = true면 구름이 이동 가능하며 이동 거리를 구하기위해 idx++

int main() {
	int N, M;
	char c[102][102];	 
	int ret[102][102];
	memset(ret, -1, sizeof(ret));
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {			
			cin >> c[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		int flag = 0;
		int idx = 0;
		for (int j = 0; j < M; j++) {
			if (c[i][j] == 'c')flag = 1, ret[i][j]=0,idx=0; // 구름이 이동 할 수 있음을 알리기 위해 flag=1 이후 모두 0으로 초기화
			else if (flag)idx++, ret[i][j] = idx;	//'c'가 아니면서 구름이 이동 가능
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ret[i][j] << " ";
		}cout << "\n";
	}
	return 0;
}