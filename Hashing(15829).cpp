#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<ctype.h>

int main() {
	//printf("%d", 'a' - ('a'-1));
	
	int TC;
	int h = 31, i = 0;
	int sum = 0;
	char str[51],ch='0';
	scanf("%d", &TC);
	getchar();
	
	while (ch != '\n') {
		scanf("%c", &ch);
		str[i++] = ch-'0';
	}	
		
	for (int i = 0; i < TC; i++) {
		int a = (str[i] - '0') * pow(h, i);;
		sum += (str[i] - '0')*pow(h, i);
	}
	printf("%d", sum);
	return 0;
}