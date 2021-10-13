#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEAP_LEN 100001
#define TRUE 1
#define FALSE 0
// 배열 idx가 작은경우 우선순위가 높음
typedef int HData;
typedef int Priority;

typedef struct _heapElem {
	Priority pr;
	HData data;
}HeapElem;

typedef struct _heap {
	int numOfData; // 마지막 노드의 고유번호
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
	//자식이 없으면
	if (GetLChildIDX(idx) > ph->numOfData) return 0;
	//자식이 하나면
	else if (ph->numOfData == GetLChildIDX(idx)) return GetLChildIDX(idx);
	//자식이 둘이면
	else {
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, Priority pr, HData data) {
	int idx = ph->numOfData + 1;
	HeapElem newElem = { pr,data };

	while (idx != 1) {
		if (pr < ph->heapArr[GetParentIDX(idx)].pr) { //새노드의 우선순위가 높은경우
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; // 부모노드를 한레벨 내림
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
	HData retData = ph->heapArr[1].data;// 삭제할 데이터 저장
	HeapElem lastElem = ph->heapArr[ph->numOfData];// 힙의 마지막 노드 저장

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
		if (ph->heapArr[childIdx].pr >= lastElem.pr) break; // 탈출조건
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
		
		if (num == 0 && HEmpty(&ph)) {
			printf("0\n");
			continue;
		}
		else if (num == 0&&!HEmpty(&ph)) {
			printf("%d\n",HDelete(&ph));
			continue;
		}
		else HInsert(&ph, num, num);
	}

}