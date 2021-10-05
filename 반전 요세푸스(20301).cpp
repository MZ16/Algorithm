#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct _node {
	int data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _deq {
	Node* head;
	Node* tail;
}Deque;

void DInit(Deque* deq) {
	deq->head = NULL;
	deq->tail = NULL;
}

int DEmpty(Deque* deq) {
	if (deq->head == NULL)return TRUE;
	else return FALSE;
}

void DFPush(Deque* deq, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = deq->head;

	if (DEmpty(deq))deq->tail = newNode;
	else deq->head->prev = newNode;

	newNode->prev = NULL;
	deq->head = newNode;

}

void DBPush(Deque* deq, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = deq->tail;

	if (DEmpty(deq))deq->head = newNode;
	else deq->tail->next = newNode;

	newNode->next = NULL;
	deq->tail = newNode;
}

int DFPop(Deque* deq) {
	int rData;
	Node* rNode;
	if (DEmpty(deq)) return -1;
	rData = deq->head->data;
	rNode = deq->head;
	deq->head = deq->head->next;
	free(rNode);

	//마지막 노드면
	if (deq->head == NULL)deq->tail = NULL;
	else deq->head->prev = NULL;

	return rData;
}

int DBPop(Deque* deq) {
	int rData;
	Node* rNode;
	if (DEmpty(deq)) return -1;
	rData = deq->tail->data;
	rNode = deq->tail;
	deq->tail = deq->tail->prev;
	free(rNode);

	//마지막 노드면
	if (deq->tail == NULL)deq->head = NULL;
	else deq->tail->next = NULL;

	return rData;
}


int main() {
	Deque deq;
	DInit(&deq);
	int N,K,M;
	int cnt = 0;
	int rock = 0;
	scanf("%d %d %d", &N, &K, &M);
	for (int i = 1; i <= N; i++)DBPush(&deq, i);
	
	while (!DEmpty(&deq)) {
		for (int i = 1; i <= K; i++) {
			if (rock) {
				if (i == K) {
					printf("%d\n", DBPop(&deq));
					cnt++;
				}
				else {
					DFPush(&deq, DBPop(&deq));
				}
			}
			else {
				if (i == K) {
					printf("%d\n", DFPop(&deq));
					cnt++;
				}
				else {
					DBPush(&deq, DFPop(&deq));
				}
			}
			if (M == cnt) {
				rock = 1 - rock;
				cnt = 0;
			}
		}

	}


	return 0;
}