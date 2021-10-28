#include <stdio.h>
#include <stdlib.h>
int list[100001];
int BinarySearch(int list[], int left, int right, int target) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (list[mid] == target)return 1;
		else if (list[mid]<target)left = mid +1;
		else right = mid - 1;
	}
	return 0;
}

void Merge(int list[], int left,int mid, int right) {
	int i, j, k;
	int* sortArr = (int*)malloc(sizeof(int) * (right+1));
	i = left;
	j = mid+1;
	k = left;
	while (i <= mid && j <= right) {
		if (list[i] < list[j]) sortArr[k++] = list[i++];
		else sortArr[k++] = list[j++];
	}

	if (i > mid)
		for (int x = j; x <= right; x++)sortArr[k++] = list[x];
	else
		for (int x = i; x <= mid; x++)sortArr[k++] = list[x];
	for(int i=left; i<=right; i++)list[i]=sortArr[i];
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
	int N, M;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &list[i]);
	MergeSort(list, 0, N-1);

	int num;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		printf("%d\n",BinarySearch(list, 0, N - 1, num));
	}

	return 0;
}