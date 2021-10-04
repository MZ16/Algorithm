#include<stdio.h>
#include<stdlib.h>
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

void EnQ(Queue* pq,int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if (QEmpty(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
	cnt++;
}

int DeQ(Queue* pq) {
	int rdata;
	Node* rNode;
	if (QEmpty(pq)) {
		printf("Queue Memory Error!\n");
		exit(1);
	}
	rdata = pq->front->data;
	rNode = pq->front;
	pq->front = pq->front->next;
	free(rNode);
	cnt--;
	return rdata;
}

int main() {
	Queue pq;
	QInit(&pq);
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		EnQ(&pq, i);
	}
	printf("<");
	while (!QEmpty(&pq)) {
		for (int i = 1; i <= K; i++) {
			if (i == K) {
				if (cnt == 1) printf("%d", DeQ(&pq));					
				else printf("%d, ", DeQ(&pq));				
			}
			else EnQ(&pq, DeQ(&pq));
		}
	}

	printf(">");

	return 0;
}

/*
* 문제를 완전 잘못이해함 K보다 작으면 큐를 전부DeQ 해주는게 아니라 원형큐로 K번만큼 돌려줘야됨

*/