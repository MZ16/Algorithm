#include <stdio.h>
#include <stdlib.h>
long long list[1000001];
long long res,mid, s, e, sum;
//정렬할 필요 없이 max값만 추출 후 이분탐색 진행
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
		for (int i = 0; i < N; i++) {//나무 자르기
			if (list[i] > mid)// 남은 길이의 합
				sum += list[i] - mid;
		}
		if (sum >= M && res < mid) // 최솟값 찾기
			res = mid;

		//이분 탐색
		if (res < mid)e=mid - 1;
		else s=mid + 1;

	}
	printf("%lld", res);
	
	
	return 0;
}