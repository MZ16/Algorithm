#include <stdio.h>
#include <stdlib.h>

int main() {
	int TC,Y, X, N;
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		scanf("%d %d %d", &Y, &X, &N);
		if (N % Y) printf("%d\n", 100 * (N % Y) + N / Y + 1);
		else printf("%d\n", 100 * Y + N / Y);		
	}
	return 0;
}
