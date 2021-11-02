#include <stdio.h>
#include <stdlib.h>

int dp[41];

int fibo(int N) {
	if (N <= 0) {
		dp[0] = 0;
		return 0;
	}
	else if (N == 1) {
		dp[1] = 1;
		return 1;
	}
	else {
		if (dp[N] != 0)return dp[N];
		else return dp[N] = fibo(N - 1) + fibo(N - 2);
	}
}

int main() {
	int TC;
	scanf("%d", &TC);
	for (int num,i = 0; i < TC; i++) {
		scanf("%d", &num);		
		if (num == 0)printf("1 0\n");
		else if (num == 1)printf("0 1\n");
		else {			
			fibo(num);
			printf("%d %d\n", dp[num-1], dp[num]);
		}
	}
	return 0;
}
