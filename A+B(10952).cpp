#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M;
	while (1) {
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0)break;
		else printf("%d\n", N + M);
	}
	return 0;
}
