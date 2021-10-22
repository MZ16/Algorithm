#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _str {
	char string[21];
}Str;

int N, M, count = 0;
int cnt = 0;
Str str[500001];
Str result[500001];

void BinarySearch(char target[]) {
	int left = 0;
	int right = M;
	int mid=(left+right)/2;
	while (left <= right) {
		mid = (left + right) / 2;
		if (strcmp(str[mid].string, target)==0) {
			result[count++] = str[mid];
			return;
		}
		else if (strcmp(str[mid].string, target) < 0) {
			left = mid + 1;
		}
		else if (strcmp(str[mid].string, target) > 0) {
			right = mid - 1;
		}
	}
	return;
}

void Merge(Str *list, int left, int mid, int right) {
	int i, j, k;
	Str* sortArr = (Str*)malloc(sizeof(Str) * (N + 1));
	i = left;
	j = right;
	k = left;
	while (i <= mid && j <= right) {
		if (strcmp(str[i].string, list[j].string)<0) sortArr[k++] = list[i++];
		else sortArr[k++] = list[j++];
	}

	if (i > mid)
		for (int x = j; x <= right; x++)
			sortArr[k++] = list[x];
	else
		for (int x = i; x <= mid; x++)
			sortArr[k++] = list[x];
	for (int i = left; i <= right; i++)  list[i]=sortArr[i];
	free(sortArr);
}

void MergeSort(Str *list, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(list, left, mid);
		MergeSort(list, mid+1, right);
		Merge(list, left, mid, right);
	}
}

int main() {
	
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", str[i].string);
	}
	MergeSort(str, 0, N-1);
	
	char st[21];
	
	for (int val,i = 0; i < M; i++) {		
		scanf("%s", &st);
		BinarySearch(st);
	}
	MergeSort(result, 0, count-1);
	printf("%d\n", count);

	for (int i = 0; i < count; i++)printf("%s\n", result[i].string);
}