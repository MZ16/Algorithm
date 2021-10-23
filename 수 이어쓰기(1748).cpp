#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include <ctype.h>

int main() {
	char str[10];
	scanf("%s", &str);
	int len = strlen(str);
	int num = atoi(str);
	int result = 0;
	for (int i = len; i > 0; i--) {
		result += ((num - (pow(10, i - 1) - 1)) * i);
		num -= (num - (pow(10, i - 1) - 1));
	}
	printf("%d", result);
	return 0;
}