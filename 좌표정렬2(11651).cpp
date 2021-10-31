#include <stdio.h>
#include <stdlib.h>

typedef struct _pos {
	int x;
	int y;
}Pos;

void Merge(Pos* list, int left, int mid, int right) {
	int i, j, k;
	Pos* sortArr = (Pos*)malloc(sizeof(Pos) * (right + 1));
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if (list[i].y < list[j].y) {
			sortArr[k++] = list[i++];
		}
		else if (list[i].y > list[j].y) {
			sortArr[k++] = list[j++];
		}
		else {//같을 경우
			if(list[i].x<list[j].x)
				sortArr[k++] = list[i++];
			else if (list[i].x > list[j].x)
				sortArr[k++] = list[j++];
		}
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

void MergeSort(Pos* list, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(list, left, mid);
		MergeSort(list, mid+1, right);
		Merge(list, left, mid, right);
	}
}



int main() {
	int TC;	
	scanf("%d", &TC);
	Pos* list = (Pos*)malloc(sizeof(Pos) * (TC+1));
	for (int i = 0; i < TC; i++) 
		scanf("%d %d", &list[i].x, &list[i].y);
	MergeSort(list, 0, TC - 1);
	for (int i = 0; i < TC; i++)
		printf("%d %d\n", list[i].x, list[i].y);
	return 0;
}