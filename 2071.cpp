#include <stdio.h>
#include <stdlib.h>
#include <math.h>	


int main() {
	int TC, sum;
	scanf("%d", &TC);
	int* arr = (int*)malloc(sizeof(int) * 10);
	for (int i = 1; i <= TC; i++) {
		sum = 0;
		for (int j = 0; j < 10; j++) {
			scanf("%d", &arr[j]);
			sum += arr[j];
		}double ans = (double)sum / 10;
		printf("#%d %d\n", i, (int)(ans+0.5));
	}
	return 0;
}