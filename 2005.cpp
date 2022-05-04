#include <iostream>
#include <stdio.h>
using namespace std;

int arr[10][10];
int TC, N;

int main() {
	cin >> TC;
	for (int x = 1; x <= TC; x++) {
		cin >> N;
		arr[0][0] = { 1 };
		for (int i = 1; i < N; i++) { // 루트노드는 처리되었으니 depth 1부터
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i)arr[i][j] = 1; // 좌우 끝 노드 1 처리
				else arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]; // depth-1과 그 왼쪽의 합이 현재노드의 값
			}
		}
		
		printf("#%d\n", x);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				printf("%d ", arr[i][j]);
			}printf("\n");
		}

	}
	return 0;
}