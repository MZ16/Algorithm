#include <stdio.h>
#include <stdlib.h>
long long list[1000001];
long long res,mid, s, e, sum;
//������ �ʿ� ���� max���� ���� �� �̺�Ž�� ����
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &list[i]);
		if (e <= list[i])e = list[i];
	}
	while (s <= e) {
		mid = (s + e) / 2;
		sum = 0;
		for (int i = 0; i < N; i++) {//���� �ڸ���
			if (list[i] > mid)// ���� ������ ��
				sum += list[i] - mid;
		}
		if (sum >= M && res < mid) // �ּڰ� ã��
			res = mid;

		//�̺� Ž��
		if (res < mid)e=mid - 1;
		else s=mid + 1;

	}
	printf("%lld", res);
	
	
	return 0;
}