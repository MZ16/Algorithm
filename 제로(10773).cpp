#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct _node {
	struct _node* prev;
	int data;
}Node;

typedef struct _stack {
	Node* head;
}LStk;

void Init(LStk * list) {
	list->head = NULL;
}

int LEmpty(LStk *list) {
	if (list->head != NULL)return FALSE;
	else if (list->head == NULL) return TRUE;
}

void LPush(LStk* list, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = list->head;
	list->head = newNode;
}

int LPop(LStk* list) {
	int rdata;
	Node* rNode;
	if (LEmpty(list))return 0;
	else {
		rdata = list->head->data;
		rNode = list->head;
		list->head = list->head->prev;
		free(rNode);
	}
	return rdata;
}

int main() {
	LStk list;
	Init(&list);
	int TC,num;
	
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		scanf("%d", &num);
		if (num == 0) LPop(&list);
		else LPush(&list, num);					
	}

	int sum = 0;
	while (!LEmpty(&list)) {
		sum += LPop(&list);
	}
	printf("%d", sum);
	return 0;
}
/*0일경우 pop TC가 끝나면 스택에 남아있는 자료를 pop해주면서 더하면 됨*/