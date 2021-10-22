#include <stdio.h>
#include <stdlib.h>
//정렬 후 UpperBound, LowBound 차를 구함
int arr[500001];
int N, M;
int Low(int val) {
	int left = 0;
	int right = N;
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] < val)left = mid + 1;
		else right = mid;
	}
	return right;
}
int Upper(int val) {
	int left = 0;
	int right = N;
	while (left < right) {
		int mid = (left + right) / 2;
		if (arr[mid] <= val)left = mid + 1;
		else right = mid;
	}
	return right;
}

void Merge(int list[], int left, int mid, int right) {
	int i, j, k;
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if (list[i] < list[j]) sortArr[k++] = list[i++];
		else sortArr[k++] = list[j++];
	}
	if (i > mid)
		for (int x = j; x <= right; x++) sortArr[k++] = list[x];
	else
		for (int x = i; x <= mid; x++)sortArr[k++] = list[x];
	for (int i = left; i <= right; i++) list[i] = sortArr[i];
	free(sortArr);
}

void MergeSort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(list, left, mid);
		MergeSort(list, mid + 1, right);
		Merge(list, left, mid, right);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	MergeSort(arr, 0, N - 1);
	scanf("%d", &M);
	for (int val, i = 0; i < M; i++) {
		scanf("%d", &val);
		printf("%d ",Upper(val)-Low(val));
	}
	return 0;
}