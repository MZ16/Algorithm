#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEAP_LEN 100001
#define TRUE 1
#define FALSE 0
// �迭 idx�� ������� �켱������ ����
typedef int HData;
typedef float Priority;

typedef struct _heapElem {
	Priority pr;
	HData data;
}HeapElem;

typedef struct _heap {
	int numOfData; // ������ ����� ������ȣ
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph) {
	ph->numOfData = 0;
}

int HEmpty(Heap* ph) {
	if (ph->numOfData == 0) return TRUE;
	else return FALSE;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}
int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}
int GetParentIDX(int idx) {
	return idx / 2;
}

int GetHiPriChildIDX(Heap* ph, int idx) {

	if (GetLChildIDX(idx) > ph->numOfData) return 0;

	else if (ph->numOfData == GetLChildIDX(idx)) return GetLChildIDX(idx);

	else {
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr) {
			//if(GetLChildIDX(idx)>GetRChildIDX(idx))
			printf("GetR : %d\n", GetRChildIDX(idx));
			printf("ph->heapArr[GetR].pr : %lf\n", ph->heapArr[GetRChildIDX(idx)].pr);
			return GetRChildIDX(idx);
		}
		
		else {
			printf("GetL : %d\n", GetLChildIDX(idx));
			printf("ph->heapArr[GetL].pr : %lf\n", ph->heapArr[GetLChildIDX(idx)].pr);
			return GetLChildIDX(idx);
		}
	}
}

void HInsert(Heap* ph, Priority pr, HData data) {
	int idx = ph->numOfData + 1;
	HeapElem newElem = { pr,data };

	while (idx != 1) {
		if (pr < ph->heapArr[GetParentIDX(idx)].pr) { //������� �켱������ �������
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; // �θ��带 �ѷ��� ����
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
	HData retData = ph->heapArr[1].data;// ������ ������ ����
	HeapElem lastElem = ph->heapArr[ph->numOfData];// ���� ������ ��� ����

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
		if (ph->heapArr[childIdx].pr >= lastElem.pr) break; // Ż������
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapArr[parentIdx] = lastElem;
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
		if (num == 0 && HEmpty(&ph)) printf("0\n");
		else if (num == 0 && !HEmpty(&ph)) printf("%d\n", HDelete(&ph));
		else if (num < 0) {
			float abs = (num * -1) - 0.01;
			HInsert(&ph, abs, num);
		}
		else if(num>0)HInsert(&ph, num , num);
	}
}
/*
18
1 -1 0 0 0 1 1 -1 -1 2 -2 0 0 0 0 0 0 0
*/