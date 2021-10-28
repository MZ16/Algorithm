#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	char str[11];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &str[i]);
		str[i] = pow(str[i], 2);
		sum += str[i];
		
	}
	printf("%d ", sum%10);

	return 0;
}
