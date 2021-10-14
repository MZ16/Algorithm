#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100001
//.
typedef int HData;
typedef int Priority;

typedef struct _heapElem {
	HData data;
	Priority pr;
}HeapElem;

typedef struct _heap {
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph) {
	ph->numOfData = 0;
}

int HEmpty(Heap* ph) {
	if (ph->numOfData == 0)return TRUE;
	else return FALSE;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}
int GetRChildIDX(int idx) {
	return idx * 2+1;
}
int GetParentIDX(int idx) {
	return idx / 2;
}

int GetHiPriChildIDX(Heap* ph,int idx) { 
	if (ph->numOfData < GetLChildIDX(idx)) return 0;
	else if (ph->numOfData == GetLChildIDX(idx)) return GetLChildIDX(idx);
	else {
		if (ph->heapArr[GetLChildIDX(idx)].pr < ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap *ph, Priority pr, HData data) {
	int idx = ph->numOfData + 1;
	HeapElem newElem = { pr,data };
	while (idx != 1) {
		if (pr > ph->heapArr[GetParentIDX(idx)].pr) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else {
			break;
		}
	}
	ph->heapArr[idx] = newElem;
	ph->numOfData++;
}

HData HDelete(Heap* ph) {
	HData retData = ph->heapArr[1].data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	int parent = 1;
	int childIDX;
	while (childIDX = GetHiPriChildIDX(ph, parent)) {
		if (ph->heapArr[childIDX].pr <= lastElem.pr)break;
		ph->heapArr[parent] = ph->heapArr[childIDX];
		parent = childIDX;
	}
	ph->heapArr[parent] = lastElem;
	ph->numOfData--;
	return retData;
}

int main() {
	Heap ph;
	HeapInit(&ph);
	int N;
	scanf("%d", &N);
	for (int num,i = 1; i <= N; i++) {
		scanf("%d", &num);
		if (num == 0 && HEmpty(&ph)) {
			printf("0\n");
		}
		else if (num == 0 && !HEmpty(&ph)) {
			printf("%d\n", HDelete(&ph));
		}
		else {
			HInsert(&ph, num, num);
		}
	}
}