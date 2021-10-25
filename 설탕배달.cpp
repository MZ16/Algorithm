#include <stdio.h>
#include <stdlib.h>


int main() {
	int N;
	scanf("%d", &N);
	int result = 0;
	while (N >= 0) {
		if (N % 5 == 0) {
			result += (N / 5);
			printf("%d", result);
			return 0;
		}N -= 3; result++;
	}printf("-1");
	return 0;
}