#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/* N�� ������ N<=10,000,000 �̰�
* �Է°����� ���� ������ 10,000����������
* ī������ ���� Ǫ�°� �����ϴ�
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