#include <stdio.h>
#include <stdlib.h>

int main() {
	int N,sum=0;
	int arr[6] = { 500,100,50,10,5,1 };
	scanf("%d", &N);
	N = 1000 - N;
	for (int i = 0; i < 6; i++) {
		if (N >= arr[i]&&N!=0) {
			sum += N / arr[i];
			N %= arr[i];
		}		
	}
	printf("%d", sum);
}