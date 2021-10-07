#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
#define TRUE 1
#define FALSE 0

typedef struct _node {
	int data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _ndoe {
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
	if (DEmpty(deq)) {
		
		return -1;
	}
	rData = deq->head->data;
	rNode = deq->head;
	deq->head = deq->head->next;
	free(rNode);

	if (deq->head == NULL) deq->tail = NULL;
	else deq->head->prev = NULL;
	return rData;
	
}

int DBPop(Deque* deq) {
	int rData = deq->tail->data;
	Node* rNode = deq->tail;
	if (DEmpty(deq)) {
		
		return -1;
	}
	deq->tail = deq->tail->prev;
	free(rNode);

	if (deq->tail == NULL)deq->head = NULL;
	else deq->tail->next = NULL;
	return rData;
}



int main() {
	

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		Deque deq;
		DInit(&deq);
		string arr; // RD
		cin >> arr;

		int N;
		scanf("%d", &N);
		
		string arr2; 
		cin >> arr2;

		string tmp; // 두자릿수 이상을 처리하기 위함
		for (int j = 0; j < arr2.length(); j++) {
			if (arr2[j] == '[')continue;
			else if (arr2[j] >= '0' && arr2[j] <= '9') tmp += arr2[j];
			else if (arr2[j] == ',' || arr2[j] == ']') {
				if (!tmp.empty()) {
					DBPush(&deq, stoi(tmp));
					tmp.clear();
				}				
			}
		}

		int rock = 1; 
		int print = 1;
		for (int i = 0; i < arr.length(); i++) {
			if (arr[i] == 'R') rock = rock - 1;
			else if (arr[i] == 'D') {
				if (DEmpty(&deq)) {
					print = 0;
					printf("error\n");
					break;
				}
				else {
					if (rock) {
						DFPop(&deq);
					}
					else {
						DBPop(&deq);
					}
				}
				
			}
		}
		if (print) { //출력
				printf("[");
				while (!DEmpty(&deq)) {
					if (rock) {
						printf("%d", DFPop(&deq));
						if (!DEmpty(&deq))printf(",");
					}
					else { 
						printf("%d", DBPop(&deq));
						if (!DEmpty(&deq))printf(",");
					}
				}printf("]\n");
		}
		
	}
	return 0;
}