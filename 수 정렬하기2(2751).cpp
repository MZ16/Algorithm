#include <stdio.h>

void Merge(int arr[], int left, int mid, int right) {
	int arr2[1000000];
	int i = left, j = mid+1, k=0;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) arr2[k++] = arr[i++];
		else arr2[k++] = arr[j++];
	}
	while (i <= mid)arr2[k++] = arr[i++];
	while (j <= right)arr2[k++] = arr[j++];
	k--;
	while (k >= 0) {
		arr[left + k] = arr2[k];
		k--;
	}
}

void MergeSort(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}

int main() {
	int arr[1000000];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)scanf("%d", &arr[i]);
	MergeSort(arr, 0, N - 1);
	for (int i = 0; i < N; i++)printf("%d ", arr[i]);
}