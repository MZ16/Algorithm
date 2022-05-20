#include <iostream>
#include <stdio.h>
using namespace std;

// 파리퇴치. 2001
/* 2차원 배열값의 범위합중 max를 구하는 문제 / brute force문제
* 
*/

int main() {
	int TC, N, M;
	int v[16][16];
	cin >> TC;
	for (int x = 1; x <= TC; x++) {
		cin >> N >> M;
		int max = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> v[i][j];
			}
		}
		//N-M으로 배열 범위 초과 방지
		for (int k = 0; k <= N-M; k++) { // i 인덱스 증가
			for (int l = 0; l <= N - M; l++) { // j 인덱스 증가
				int sum = 0;
				for (int i = k; i < M + k; i++) {
					for (int j = l; j < M + l; j++) {
						sum += v[i][j];
					}
				}
				max = max < sum ? sum : max;
			}
			
		}printf("#%d %d\n", x, max);

	}

}