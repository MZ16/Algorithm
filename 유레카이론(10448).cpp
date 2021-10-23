#include <stdio.h>
#include <stdlib.h>
// 최대 3개의 삼각형 합까지 가능
int main() {
	int N, b = 0;
	int val = 2;
	int result = 0;
	int arr[44] = { 1 };
	for (int i = 1; i < 44; i++) 
		arr[i] = arr[i-1] + val++;
	scanf("%d", &N);
	while (N--) {
		int num;
		scanf("%d", &num);
		for (int i = 0; i < 44; i++)
			for (int j = 0; j < 44; j++) {
				for (int k = 0; k < 44; k++) {
					result = arr[i] + arr[j] + arr[k];
					if (result == num)b = 1;
				}
			}
		if (b)printf("1\n");
		else printf("0\n");
		b = 0;
	}
	
	
	return 0;
}