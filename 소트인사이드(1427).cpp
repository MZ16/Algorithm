#include <stdio.h>
#include <stdlib.h>

void Merge(int list[], int left, int mid, int right) {
	int i, j, k;
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if (list[i] < list[j])
			sortArr[k++] = list[j++];
		else sortArr[k++] = list[i++];
	}
	if (i > mid)
		for (int x = j; x <= right; x++)
			sortArr[k++] = list[x];
	else
		for (int x = i; i <= mid; i++)
			sortArr[k++] = list[i];
	for (int i = left; i <= right; i++)list[i] = sortArr[i];
	free(sortArr);
}

void MergeSort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(list, left, mid);
		MergeSort(list, mid+1, right);
		Merge(list, left, mid, right);
	}
}

int main() {
	int list[11];
	int N,len=0;
	scanf("%d", &N);
	while (N > 0) {
		list[len] = N % 10;
		N /= 10;		
		len++;
	}
	MergeSort(list, 0, len-1); // 내림차순

	for (int i = 0; i < len; i++)printf("%d", list[i]);
}