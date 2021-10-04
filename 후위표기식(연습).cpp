#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _node {
	struct _node* prev;
	char data;
}Node;

typedef struct _stk {
	Node* head;
}Lstk;

void Linit(Lstk *stk) {
	stk->head = NULL;
}

int Lempty(Lstk* stk) {
	if (stk->head == NULL)return 1;
	return 0;
}

void Lpush(Lstk* stk, char data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = stk->head;
	stk->head = newNode;
}

char Lpop(Lstk* stk) {
	char rdata;
	Node* rNode;
	if (Lempty(stk)) {
		printf("Stack Empty!");
		exit(1);
	}
	rdata = stk->head->data;
	rNode = stk->head;
	stk->head = stk->head->prev;
	free(rNode);
	return rdata;
}

char Ltop(Lstk* stk) {
	return stk->head->data;
}

int GetOpPrec(char op) {
	switch (op) {
	case '(':
			return 1;
	case '+': case '-':
		return 2;
	case '*': case '/':
		return 3;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec) return 1; // stack의 연산자 순위가 높음, pop을 의미
	else if (op1Prec == op2Prec) return 0; // 마찬가지
	else if(op1Prec < op2Prec)return -1; // push
}

void ConvToRPNExp(char exp[]) {
	Lstk stk;
	Linit(&stk);
	int len = strlen(exp);
	char* ConvExp = (char*)malloc(len + 1);// 피연산자와 연산자를 담을 공간
	memset(ConvExp, 0, sizeof(char) * len + 1);// ConvExp 초기화 
	//ConvExp는 char형 메모리임으로 초기화도 char * len+1임
	
	char tok, POP;
	int idx = 0;
	for (int i = 0; i < len; i++) {
		tok = exp[i];
		if (tok >= 65 && tok <= 90) ConvExp[idx++] = tok;
		else {
			switch (tok) { //switch쓰면서 break를 안썻음...
			case '(':
				Lpush(&stk, tok); break;
			case')':// 여는괄호를 만날때까지 스택에 있는값을 전부 뺴야됨
				while (1) {
					POP = Lpop(&stk); // 먼저 pop을 실행시켰음으로 이다음 if문에서 stack은 empty
					if (POP == '(')break;
					ConvExp[idx++] = POP;
				}break;
			case '+':case '-':
			case '*':case '/':
				while (!Lempty(&stk) && WhoPrecOp(Ltop(&stk), tok) >= 0)//스택에있는 연산자 우선순위를 비교해서 Pop일경우 계속 비교해야됨
					ConvExp[idx++] = Lpop(&stk); 
				Lpush(&stk, tok); // push는 tok의 우선순위가 높을때 발생
				break;
			}
		}
	}
	while (!Lempty(&stk))
		ConvExp[idx++] = Lpop(&stk);
	strcpy(exp, ConvExp);
	free(ConvExp);
}



int main() {
	char Conv[100];
	scanf("%s", Conv);
	ConvToRPNExp(Conv);
	printf("%s", Conv);
	return 0;
}