#include <stdio.h>

int main() {
	int T,d1,d2;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d", &d1, &d2);
		printf("Case #%d: %d + %d = %d\n", i, d1, d2, d1 + d2);
	}
}