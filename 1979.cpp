#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// 어디에 단어가 들어갈 수 있을까
/* 맵의 가로, 세로에 대한 빈칸을 확인한다
* 1. 가로가 1일때 빈칸갯수를 증가시키고 
	 빈캇갯수가 K보다 크다면 빈칸을 0으로 초기화
	 idx가 끝이고 빈칸갯수가 K와 같다면 ans를 증가시킴
  2. 가로가 0일때 빈칸갯수가 K와 같다면 ans를 증가시킴
	 빈칸개수를 0으로 초기화
* 3. 세로도 위와 마찬가지
*/

int main() {
	int TC, N, K;
	cin >> TC;
	for (int x = 1; x <= TC; x++) {
		int arr[15][15];
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		
		
		int ans = 0;
		
		//가로
		for (int i = 0; i < N; i++) {
			int colCnt = 0;
			for (int j = 0; j < N; j++) {
				if (arr[i][j]) { // 1인 경우
					colCnt++;
					if (colCnt > K)colCnt = 0; 
					if (j == N - 1 && colCnt == K)ans++;
				}
				else { // 0인 경우
					if (colCnt == K)ans++;
					colCnt = 0;
				}
			}
		}

		//세로
		for (int i = 0; i < N; i++) {
			int rowCnt = 0;
			for (int j = 0; j < N; j++) {
				if (arr[j][i]) { // 1인 경우
					rowCnt++;
					if (rowCnt > K)rowCnt = 0;
					if (j == N - 1 && rowCnt == K)ans++;
				}
				else { // 0인 경우
					if (rowCnt == K)ans++;
					rowCnt = 0;
				}
			}
		}
		printf("#%d %d\n", x, ans);
		ans = 0;

	}

}