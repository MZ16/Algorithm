#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<ctype.h>
#define mod 1234567891

int main() {
	//printf("%d", 'a' - ('a'-1));
	
	int TC;
	int i = 0;
	long long sum = 0,r=1;
	char str[51],ch='0';
	scanf("%d", &TC);
	getchar();
	
	while (ch != '\n') {
		scanf("%c", &ch);
		str[i++] = ch-'0';
	}	
		
	for (int i = 0; i < TC; i++) {
		sum +=  ((str[i] - '0')*r)%mod;
		r = (r * 31) % mod;
	}
	printf("%lld", sum);
	return 0;
}