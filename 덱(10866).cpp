#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int cnt;

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
	cnt++;
}

void DBPush(Deque* deq, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = deq->tail;

	if (DEmpty(deq))deq->head = newNode;
	else deq->tail->next = newNode;

	newNode->next = NULL;
	deq->tail = newNode;
	cnt++;
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
	cnt--;
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

	cnt--;
	return rData;
}

int DFPeek(Deque* deq) {
	if (DEmpty(deq)) return -1;
	return deq->head->data;
}

int DBPeek(Deque* deq) {
	if (DEmpty(deq)) return -1;
	return deq->tail->data;
}

int main() {
	Deque deq;
	DInit(&deq);
	int N;
	char op[12];
	scanf("%d", &N);
	for (int val,i = 0; i < N; i++) {
		scanf("%s", op);
		if (!strcmp(op, "push_front")) {
			scanf("%d", &val);
			DFPush(&deq, val);
		}
		else if (!strcmp(op, "push_back")) {
			scanf("%d", &val);
			DBPush(&deq, val);
		}
		else if (!strcmp(op, "pop_front")) {
			printf("%d\n", DFPop(&deq));
		}
		else if (!strcmp(op, "pop_back")) {
			printf("%d\n", DBPop(&deq));
		}
		else if (!strcmp(op, "size")) {
			printf("%d\n", cnt);
		}
		else if (!strcmp(op, "empty")) {
			printf("%d\n", DEmpty(&deq));
		}
		else if (!strcmp(op, "front")) {
			printf("%d\n", DFPeek(&deq));
		}
		else if (!strcmp(op, "back")) {
			printf("%d\n", DBPeek(&deq));
		}
	}
	
	return 0;
}