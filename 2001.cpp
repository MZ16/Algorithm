#include <iostream>
#include <stdio.h>
using namespace std;

// �ĸ���ġ. 2001
/* 2���� �迭���� �������� max�� ���ϴ� ���� / brute force����
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
		//N-M���� �迭 ���� �ʰ� ����
		for (int k = 0; k <= N-M; k++) { // i �ε��� ����
			for (int l = 0; l <= N - M; l++) { // j �ε��� ����
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