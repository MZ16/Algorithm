#include <stdio.h>

//��Ŭ���� ȣ����
int Euclidean(int a, int b) {
	if (b == 0)return a;
	return Euclidean(b, a % b);
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int lcm = (N * M) / Euclidean(N, M);
	printf("%d\n", Euclidean(N, M));
	printf("%d\n", lcm);
	return 0;
}