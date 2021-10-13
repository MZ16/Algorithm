#include <stdio.h>

int main() {
	int N,a,b,c;
	int cnt = 99; // 100이하는 모두 등차수열
	scanf("%d", &N);
	if (N < 100) {
		printf("%d", N);
		return 0;
	}
	for (int i = 100; i <= N; i++) {
		a = i / 100;
		b = i / 10 % 10;
		c = i % 10;
		if ((b - a) == (c - b))cnt++;
	}printf("%d", cnt);
}
// 한수 - 각 자릿수가 등차수열을 이룬다.
// 3자릿수를 a,b,c라 할때 등차수열을 검증하는 방법은 b-a == c-b 이다.