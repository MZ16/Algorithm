#include <stdio.h>

int main() {
	int a,b,v;
	int cnt=0,ans=0;
	scanf("%d %d %d", &a,&b,&v);
	printf("%d", (v - b - 1) / (a - b) + 1);
	return 0;
}