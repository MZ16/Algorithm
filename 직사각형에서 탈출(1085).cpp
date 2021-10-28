#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	w -= x;
	h -= y;
	x = w >= x ? x : w;
	y = h >= y ? y : h;
	printf("%d", x>=y?y:x);
	

	return 0;
}