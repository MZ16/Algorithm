#include <stdio.h>
int main() {
	int N; scanf("%d", &N);
	if (N >= 90 && N <= 100)printf("A"); else if (N >= 80 && N < 90)printf("B"); else if (N >= 70 && N < 80)printf("C"); else if (N >= 60 && N < 70)printf("D"); else printf("F");
}