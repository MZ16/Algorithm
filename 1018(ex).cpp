#include <bits/stdc++.h>
using namespace std;

string s[51];
int N, M, ans=987654321;

string BW[8]{
	"BWBWBWBWBW",
	"WBWBWBWBWB",
	"BWBWBWBWBW",
	"WBWBWBWBWB",
	"BWBWBWBWBW",
	"WBWBWBWBWB",
	"BWBWBWBWBW",
	"WBWBWBWBWB"
};
string WB[8]{
	"WBWBWBWBWB",
	"BWBWBWBWBW",
	"WBWBWBWBWB",
	"BWBWBWBWBW",
	"WBWBWBWBWB",
	"BWBWBWBWBW",
	"WBWBWBWBWB",
	"BWBWBWBWBW"
};

int BW_cnt(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s[y + i][x + j] != BW[i][j])cnt++; // 셋팅된BW 맵과 입력된 맵을 비교
		}
	}
	return cnt;
}
int WB_cnt(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s[y + i][x + j] != WB[i][j])cnt++; // 셋팅된WB 맵과 입력된 맵을 비교
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> s[i];

	for (int i = 0; i <= N-8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int tmp = min(BW_cnt(i,j), WB_cnt(i,j));
			ans = min(ans, tmp);
		}
	}
	cout << ans;

	return 0;
}

/*
* 1. 검흰, 흰검 8*8 셋팅
* 2. 입력된 맵과 셋팅값을 비교하여 다르게 입력된 부분 카운팅
* 3. 맵 전체를 순회하며 min값을 counting
*/