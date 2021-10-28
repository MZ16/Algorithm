#include <stdio.h>
#include <stdlib.h>
// 에라토스테네스의 체
int arr[1000001];
int main() {
	int M, N;
	arr[1] = 1;
	scanf("%d %d", &M, &N);
	for (int i = 2; i <= N; i++) 
		for (int j = 2; j * i <= N; j++) arr[i*j] = 1;
	
	for (int i = M; i <= N; i++) if(!arr[i])printf("%d\n", i);		
	return 0;
}

