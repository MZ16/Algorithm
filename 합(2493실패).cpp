#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
int idx = -1;

typedef struct _node {
	struct _node* prev;
	int data;
}Node;

typedef struct _stk {
	Node* head;
}Lstk;

void Linit(Lstk * stk) {
	stk->head = NULL;
}

int Lempty(Lstk* stk) {
	if (stk->head == NULL)return 1;
	return 0;
}

int Ltop(Lstk* stk) {
	return stk->head->data;
}

int Lprev(Lstk* stk) {
	if (stk->head->prev!=NULL)return stk->head->prev->data;
	else if(stk->head->prev==NULL)return 0;
}

void Lpush(Lstk* stk, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = stk->head;
	stk->head = newNode;
}

int Lpop(Lstk* stk) {
	int rdata;
	Node *rNode;
	if (Lempty(stk)) {
		printf("Stack Empty!\n");
		exit(1);
	}
	rdata = stk->head->data;
	rNode = stk->head;
	stk->head = stk->head->prev;
	free(rNode);	
	return rdata;
}

int WhoPrecOp(int op1,int op2) {
	if (op1 > op2) return 1;
	else if (op1 == op2) return 0;
	else if (op1 < op2) return -1;
}

void Conv(Lstk *stk) {	
	
	int arr[50000] = { 0, };
	int arrPush[50000] = { 0, };
	int len = 0;
	
	int tok,Prev;
	//int len = idx;
	for (int i = idx; i > 0; i--) {
		//5번을 반복, 
	// 7 4까진 잘됨, 그담에 5를 생략시킴
	int val = i;
	
		tok = Ltop(stk);
		Lpop(stk);
		Prev = Ltop(stk);
		while (!Lempty(stk) && (WhoPrecOp(Prev, tok) < 0)) {
			
			//printf("1\n");
			if (Lprev(stk)) {
				arrPush[len++] = Lpop(stk);
				Prev = Ltop(stk);
				val--;
			}
			else {
				val = 0; break;
			}
			
		}
		if (val <= 0)arr[i] = 0;
		else arr[i] = val; 
		
		
		for (int i = 0; i < len; i++) {
			Lpush(stk, arrPush[i]);
		}
		len = 0;
		memset(arrPush, 0, sizeof(arrPush));
		
		
	}
	for (int i = 0; i <= idx; i++) {
		printf("%d ", arr[i]);
	}
}

int main() {
	Lstk stk;
	int TC; // 50만 이하
	int val; // 1억 이하
	scanf("%d", &TC);
	
	Linit(&stk);
	for (int i = 0; i < TC; i++) {
		scanf("%d", &val); Lpush(&stk, val);	
		idx++;
	}

	Conv(&stk);
	

	return 0;
}