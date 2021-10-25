#include <stdio.h>
#include <stdlib.h>

int arr[1001];
int main() {
	int N,M;
	float max = 0;
	float ans=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (max < arr[i])max = arr[i];
	}
	for (int i = 0; i < N; i++) {
		ans += ((arr[i] / max) * 100);
	}
	printf("%.2f", ans/N);

	return 0;
}

