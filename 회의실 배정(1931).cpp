#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct _pos {
	int x;
	int y;
}Pos;

void merge(Pos *list, int left, int mid, int right)
{
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;
	Pos* sortArr = (Pos*)malloc(sizeof(Pos) * (right + 1));
	while (i <= mid && j <= right) {
		if (list[i].y < list[j].y) sortArr[k++] = list[i++];
		else if(list[i].y>list[j].y) sortArr[k++] = list[j++];
		else {
			if (list[i].x < list[j].x) sortArr[k++] = list[i++];
			else sortArr[k++] = list[j++];
		}
	}
	if (i > mid)
		for (int x = j; x <= right; x++)sortArr[k++] = list[x];
	else
		for (int x = i; x <= mid; x++)sortArr[k++] = list[x];
	for (int i = left; i <= right; i++)list[i] = sortArr[i];
	free(sortArr);
}

void mergeSort(Pos *list, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(list, left, mid);
		mergeSort(list, mid+1, right);
		merge(list, left, mid, right);		
	}
}



int main() {
	int TC;
	int first=99999;
	int cnt = 0;
	scanf("%d", &TC);
	Pos* list = (Pos*)malloc(sizeof(Pos) * (TC + 1));
	for (int i = 0; i < TC; i++) {
		scanf("%d %d", &list[i].x, &list[i].y);
	}
	mergeSort(list, 0, TC - 1);

	for (int i = 0; i < TC; i++) {
		if (i == 0) {
			cnt++;
			first = list[i].y;			
		}
		else if (first <= list[i].x) {
			cnt++;
			first = list[i].y;
		}
	}
	printf("%d", cnt);
}