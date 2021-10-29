#include <stdio.h>
#include <stdlib.h>
long long N;
int main() {
	
	int sum_low = 2;
	int sum_max = 7;
	int sumresult = 0;
	int cnt = 2;
	int i = 1,idx=6;
	scanf("%lld", &N);
	while (1) {
		if (N == 1) {
			printf("1");
			return 0;
		}
		if (sum_low <= N && sum_max >= N) {
			break;
		}
		sum_low = idx * i + sum_low;
		sum_max = idx * (i + 1) + sum_max;
		cnt++;
		i++;		
	}
	printf("%d", cnt);
	return 0;
}