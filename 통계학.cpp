#include<stdio.h>
#include<stdlib.h>

int arr[500001];
int cnt[8002];//ans3

//ans2
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

int Max(int arr[], int len) { // ans3
	int max = arr[0];
	for (int i = 0; i < len; i++)
		if (max < arr[i])max = arr[i];
	return max;
}

int main() {
	int N;
	int sum = 0, chk = 0;
	int min = 4001, max = -4001;
	int ans3 = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i]; // ans1

		if (max < arr[i])max = arr[i];	//ans4
		if (min > arr[i]) min = arr[i];

		cnt[arr[i] + 4000]++; // ans3
	}

	for (int i = 0; i < 8001; i++) //ans3
		if (Max(cnt, 8001) == cnt[i]) chk++;
	for (int i = 0; i < 8001; i++)
		if (chk == 1) {
			if (Max(cnt, 8001) == cnt[i]) {
				ans3 = i - 4000;
				break;
			}
		}
		else {
			if (Max(cnt, 8001) == cnt[i]) {
				if (chk == 0) {
					ans3 = i - 4000;
					break;
				}
				else chk = 0;
			}
		}
	MergeSort(arr, 0, N - 1);

	printf("%.0f\n", (double)sum / N);
	printf("%d\n", arr[(N + 1) / 2 - 1]);
	printf("%d\n", ans3);
	printf("%d\n", max - min);

	return 0;
}