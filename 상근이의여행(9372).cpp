#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);
		for (int a,b,i = 0; i < M; i++) {
			scanf("%d %d", &a, &b);
		}printf("%d\n", N - 1);
	}
	return 0;
}