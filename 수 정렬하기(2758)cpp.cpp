#include <stdio.h>
#include <stdlib.h>

int main() {
	int N,arr[1001];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < (N - i) - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++)printf("%d\n", arr[i]);

}