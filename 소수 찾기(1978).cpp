#include <stdio.h>
#include <stdlib.h>

int main() {
	int N,cnt=0;
	int j;
	scanf("%d", &N);
	for (int val,i = 0; i < N; i++) {
		scanf("%d", &val);
		for (j = 2; j < val; j++) if (val % j == 0)break;
		if (j == val)cnt++;
	}printf("%d\n", cnt);

	return 0;
}

