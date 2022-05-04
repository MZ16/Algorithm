#include <stdio.h>
#include <stdlib.h>



int main() {
	int TC, sum;
	scanf("%d", &TC);
	int* arr = (int*)malloc(sizeof(int) * 10);
	for (int i = 1; i <= TC; i++) {
		sum = 0;
		for (int j = 0; j < 10; j++) {
			scanf("%d", &arr[j]);
			if (arr[j] % 2 != 0)sum += arr[j];
		}
		printf("#%d %d\n", i, sum);
	}
	return 0;
}