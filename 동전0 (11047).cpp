#include <stdio.h>
#include <stdlib.h>
// °¡Àå Å« ¼öºÎÅÍ
int N, K;
int arr[11];
int main() {
	int ans = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = N - 1; i >= 0; i--) {
		if (arr[i] <= K) {
			ans += (K / arr[i]);
			K %= arr[i];
		}
		else if (K == 0)break;
	}

	printf("%d", ans);


}
