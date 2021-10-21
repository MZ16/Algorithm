#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* N의 범위가 N<=10,000,000 이고
* 입력가능한 수의 범위는 10,000까지임으로
* 카운팅을 통해 푸는게 적합하다
*/
int main() {
	int N;
	scanf("%d", &N);
	int arr[10001] = { 0, };
	for (int num,i = 1; i <= N; i++) {
		scanf("%d", &num);
		arr[num]++;
	}
	for (int i = 1; i <= 10000; i++) {
		while (arr[i] != 0) {
			printf("%d\n", i);
			arr[i]--;
		}
		
	}
	
	return 0;
}