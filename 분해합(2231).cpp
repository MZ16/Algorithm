#include <stdio.h>

int main() {
	int N, tmp,cnt=0, M = 0;
	int sum = 0, num;
	scanf("%d", &N);
	tmp = N;
	while (tmp) {
		tmp /= 10;
		cnt++;
	}
	tmp = N;
	tmp = tmp - cnt * 9;
	for (int i = tmp; i <= N; i++) {
		num = i;
		sum += num;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum == N) {
			M = i;
			break;
		}sum = 0;
	}
	printf("%d", M);
}