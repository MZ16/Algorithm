#include <stdio.h>

int main() {
	int A, B, C;
	int result = 0;
	scanf("%d %d %d", &A, &B, &C);
	if (B-C >= 0) {
		printf("-1");
		return 0;
	}
	else result = A / (C - B);
	printf("%d", result+1);
	return 0;
}
