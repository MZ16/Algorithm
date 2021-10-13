#include <stdio.h>

int main() {
	int N, M;
	int arr[101];
	int MAX = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N-1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (arr[i] + arr[j] + arr[k] <= M&& MAX < arr[i] + arr[j] + arr[k])
					MAX = arr[i] + arr[j] + arr[k];
			}
		}
	}printf("%d", MAX);
}
/*
10 50000
9999 3333 5555 5 8 15000 20000 40000 30000 1
*/