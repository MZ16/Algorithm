#include <stdio.h>
int main() {
	int N, cnt = 1;
	int n1, n2;
	scanf("%d", &N);
	if (N < 10)N *= 10;
	n1 = N / 10; n2 = N % 10;
	int result = n1 + n2;
	int newNum = (n2 * 10) + result;
	while (1) {
		if(newNum == N) { printf("%d", cnt); break; }
		n1 = n2; 
		n2 = result % 10; 
		result = n1 + n2; 
		newNum = (n2 * 10) + (result%10);  
		cnt++;
	}
	return 0;
}