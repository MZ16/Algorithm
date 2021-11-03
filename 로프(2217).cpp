#include <stdio.h>
#include <stdlib.h>

void merge(int* list, int left, int mid, int right)
{
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	while (i <= mid && j <= right) {
		if (list[i] < list[j]) sortArr[k++] = list[i++];
		else  sortArr[k++] = list[j++];
	}
	if (i > mid)
		for (int x = j; x <= right; x++)sortArr[k++] = list[x];
	else
		for (int x = i; x <= mid; x++)sortArr[k++] = list[x];
	for (int i = left; i <= right; i++)list[i] = sortArr[i];
	free(sortArr);
}

void mergeSort(int* list, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(list, left, mid);
		mergeSort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}


int main() {
	int TC,min_val=99999;
	int arr[100001];
	int ans,idx=0,max=0;
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) 
		scanf("%d", &arr[i]);

	mergeSort(arr, 0, TC - 1);
	for (int i = 0; i < TC; i++) {
		ans = arr[i] * (TC - i);
		if (ans > max) {
			max = ans;
			idx = i;
		}
	}
	printf("%d", max);



	return 0;
}