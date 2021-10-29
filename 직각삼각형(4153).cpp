#include<stdio.h>
#include<math.h>
int max(int a, int b, int c) {
	if (a > b && a > c)return a;
	if (b > a && b > c)return b;
	else return c;
}
int main() {
	int a, b, c,val;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		val = max(a, b, c);
		if (a == 0 && b == 0 && c == 0)break;
		if (a == val) {
			if ((pow(c, 2) + pow(b, 2)) == pow(a, 2))printf("right\n");
			else printf("wrong\n");
		}
		else if (b == val) {
			if ((pow(a, 2) + pow(c, 2)) == pow(b, 2))printf("right\n");
			else printf("wrong\n");
		}
		else if (c == val) {
			if ((pow(a, 2) + pow(b, 2)) == pow(c, 2))printf("right\n");
			else printf("wrong\n");
		}		
	}
	
	
	return 0;
}