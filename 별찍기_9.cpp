#include <stdio.h>

int main() {
	int T,cnt=1;
	scanf("%d", &T);
	int val = T-1;
	for (int i = 1; i <= T; i++) {
		for (int j = 1; j < i; j++) printf(" ");
		for (int j = (val--) * 2 + 1; j > 0; j--) printf("*");
		printf("\n");
	}
	for (int i = 2; i <= T; i++) {
		for (int j = 0; j < T - i; j++) printf(" ");
		for (int j = i * 2 - 1; j > 0; j--) printf("*");
		printf("\n");
	}

	return 0;
}