#include <stdio.h>
#include <stdlib.h>
#include <math.h>	


int main() {
	int TC;
	scanf("%d", &TC);
	for (int x,y,i = 1; i <= TC; i++) {
		char ch;
		scanf("%d %d", &x, &y);
		if (x > y) ch = '>';
		else if (x < y) ch = '<';
		else ch = '=';
		printf("#%d %c\n", i, ch);
	}
	return 0;
}