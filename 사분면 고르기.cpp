#include <stdio.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	if (N > 0 && M > 0) printf("%d", 1);
	if (N < 0 && M > 0) printf("%d", 2);
	if (N < 0 && M < 0) printf("%d", 3);
	if (N > 0 && M < 0) printf("%d", 4);
}