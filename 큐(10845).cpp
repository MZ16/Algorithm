#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int cnt;

typedef struct _node {
	int data;
	struct _node* next;
}Node;

typedef struct _Queue {
	Node* front;
	Node* rear;
}Queue;

void QInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

int QEmpty(Queue* pq) {
	if (pq->front == NULL)return TRUE;
	else return FALSE;
}

void EnQueue(Queue* pq, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (QEmpty(pq)) { // Empty인 경우 front와 rear가 첫 노드를 가르키는것을 처리
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
	cnt++;
}

int DeQueue(Queue* pq) {
	int rdata;
	Node* rNode;
	if (QEmpty(pq)) {
		return -1;
	}
	rdata = pq->front->data;
	rNode = pq->front;
	pq->front = pq->front->next;
	free(rNode);
	cnt--;
	return rdata;
}

int QPeek(Queue* pq) {
	if (!QEmpty(pq)) return pq->front->data;
	else return -1;
}

int QBack(Queue* pq) {
	if (!QEmpty(pq)) return pq->rear->data;
	else return -1;
}


int main() {
	Queue pq;
	QInit(&pq);
	int TC,val;
	char op[10];
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		scanf(" %s", op);
		if (!strcmp(op,"push")) {
			scanf("%d", &val);
			EnQueue(&pq, val);
		}
		else if (!strcmp(op, "pop")) {
			if (QEmpty(&pq))printf("-1\n");
			else printf("%d\n", DeQueue(&pq));
		}
		else if (!strcmp(op, "size")) {
			printf("%d\n", cnt);
		}
		else if (!strcmp(op, "empty")) {
			if (QEmpty(&pq))printf("%d\n", TRUE);
			else printf("%d\n", FALSE);
		}
		else if (!strcmp(op, "front")) {
			printf("%d\n", QPeek(&pq));
		}
		else if (!strcmp(op, "back")) {
			printf("%d\n", QBack(&pq));
		}
	}

	return 0;
}
//strcmp는 같을경우 0을 반환 아니면 1이상의 수를 반환하기때문에 if문으로 비교 시 !를 붙임