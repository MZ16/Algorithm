#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 1. 문자열과 길이를 입력받을 수 있는 구조체 생성
*  2. 합병 시 길이가 같은 경우 strcmp를 통해 정렬
*  3. 출력 시 중복문자 제외
*/
typedef struct _str {
	char String[51];
	int length;
}Str;

void Merge(Str * list, int left, int mid, int right) {
	int i, j, k;
	Str* sortArr = (Str*)malloc(sizeof(Str) * (right + 1));
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if (list[i].length < list[j].length)
			sortArr[k++] = list[i++];
		else if(list[i].length>list[j].length)
			sortArr[k++] = list[j++];
		else { // 길이가 같은경우
			if(strcmp(list[i].String,list[j].String)<0)
				sortArr[k++] = list[i++];
			else 
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

void MergeSort(Str* list, int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		MergeSort(list, left, mid);
		MergeSort(list, mid+1, right);
		Merge(list, left, mid, right);
	}
}

int main() {
	int N;
	
	scanf("%d", &N);
	Str* list=(Str*)malloc(sizeof(Str)*(N+1));
	for (int i = 0; i < N; i++) {
		scanf("%s", list[i].String);
		list[i].length = strlen(list[i].String);
	}
	MergeSort(list, 0, N - 1);
	printf("%s\n", list[0].String);
	for (int i = 0; i < N; i++) {
		if (i>0&&(strcmp(list[i].String,list[i-1].String)!=0)) 
			printf("%s\n", list[i].String);
	}
	return 0;
}