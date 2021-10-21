#include<stdio.h>
#include<stdlib.h>


void Merge(int list[], int left, int mid, int right) {
	int i, j, k;
	int *sortArr = (int*)malloc(sizeof(int) * (right + 1));
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sortArr[k++] = list[i++];
		else
			sortArr[k++] = list[j++];
	}
	if (i > mid)
		for (int x = j; x <= right; x++)
			sortArr[k++] = list[x];
	else
		for (int x = i; x <= mid; x++)
			sortArr[k++] = list[x];
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
	int N,Fibo=0,sum=0;
	scanf("%d", &N);
	int* list = (int*)malloc(sizeof(int) * (N + 1));
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}
	MergeSort(list, 0, N - 1);
	for (int i = 0; i < N; i++) {
		Fibo = list[i] + Fibo;
		sum += Fibo;
	}
	printf("%d", sum);
	return 0;
}