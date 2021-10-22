#include <stdio.h>
#include <stdlib.h>
//정렬 후 이분탐색
int arr[500001];
int N, M;
void Binary(int i, int key) {
	int mid;
	int first = 0;
	int end = i - 1;
	while (first <= end) {
		mid = (first + end) / 2;
		if (arr[mid] == key) {
			printf("1 ");
			return;
		}
		else if (arr[mid] < key) {
			first = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	printf("0 ");
	return;
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
	scanf("%d",&N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	MergeSort(arr, 0, N-1);
	scanf("%d", &M);	
	for (int val, i = 0; i < M; i++) {
		scanf("%d", &val);
		Binary(N, val);
	}
	return 0;
}