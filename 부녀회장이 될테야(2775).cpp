#include <stdio.h>
int arr[15][15];
int main() {
	for (int i = 0; i < 15; i++) {
		arr[0][i] = i; 
		arr[i][1] = 1;
	}
	for (int i = 1; i < 15; i++)
		for (int j = 2; j < 15; j++) 	
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];

	int N, v1, v2;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &v1, &v2);
		printf("%d\n", arr[v1][v2]);
	}
	return 0;
}