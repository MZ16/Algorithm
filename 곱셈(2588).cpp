#include <stdio.h>
#include <stdlib.h>

int main() {
	int N; char M[4];
	scanf("%d %s", &N, &M);
	int val[4] = { M[0]-'0',M[1]-'0',M[2]-'0' };
	printf("%d\n", N*val[2]);
	printf("%d\n", N * val[1]);
	printf("%d\n", N * val[0]);
	printf("%d", N * atoi(M));
}
