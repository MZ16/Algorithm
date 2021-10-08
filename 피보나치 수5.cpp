#include <stdio.h>
#include <algorithm>
int main() {
	int T;
	scanf("%d", &T);
	int val[21] = { 0,1 };
	for (int i = 2; i <= T; i++) {
		val[i] = val[i - 1] + val[i - 2];
	}
	
	printf("%d", val[T]);
	return 0;
}