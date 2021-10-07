#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M;
	int arr[10001] = { 0, };
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] < M)printf("%d ", arr[i]);
	}
	
	return 0;
}