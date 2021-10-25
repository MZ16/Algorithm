#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int r2=0, r5=0;
	for (int i = 2; i <= N; i *= 2)r2 += N / i;
	for (int i = 5; i <= N; i *= 5)r5 += N / i;	
	printf("%d", (r2 < r5) ? r2 : r5);

	return 0;
}