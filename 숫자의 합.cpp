#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char str[101];
	int N, sum = 0;
	scanf("%d", &N);
	scanf("%s", &str);
	for (int i = 0; i < strlen(str); i++) {
		sum += str[i] - '0';
	}
	printf("%d", sum);
	return 0;
}