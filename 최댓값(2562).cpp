#include <stdio.h>

int main() {
	int val,MAX=0,cnt=0;
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &val);
		if (val > MAX) {
			MAX = val;
			cnt = i;
		}
	}printf("%d\n%d", MAX, cnt);
}