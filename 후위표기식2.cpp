#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


// double는 "-20억보다 크거나 같고 20억보다 작거나 같은" 수를 정확하게 표현하기 힘듭니다.
int TC;
typedef struct _node {
	struct _node* prev;
	double data;
}Node;

typedef struct _stk {
	Node* head;
}Lstk;

void Linit(Lstk* stk) {
	stk->head = NULL;
}

int Lempty(Lstk* stk) {
	if (stk->head == NULL)return 1;
	return 0;
}

void Lpush(Lstk* stk, double data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = stk->head;
	stk->head = newNode;
}

double Lpop(Lstk* stk) {
	double rdata;
	Node* rNode;
	if (Lempty(stk)) {
		printf("Stack empty!\n");
		exit(1);
	}
	rdata = stk->head->data;
	rNode = stk->head;
	stk->head = stk->head->prev;
	free(rNode);
	return rdata;
}


void ConvExp(char exp[],int exp2[]) {
	int len = strlen(exp);
	Lstk stk;
	Linit(&stk);
	//int cnt = 0;
	int tok;
	double pop1, pop2;

	for (int i = 0; i < len; i++) {
		tok = exp[i];
		if (tok >= 65 && tok <= 90) { // 피연산자라면 push
			Lpush(&stk, exp2[exp[i]-'A']);  

			/* 실패 이유, 조건이 너무 야매였음.
			if (cnt < TC-1) {
				Lpush(&stk, exp2[cnt++]); // 스택에 int형으로 넣기위함
			}
			else {
				Lpush(&stk, exp2[cnt]);
			}
			*/
			
		}
		else { // 연산자라면 pop2번, 연산, push
			pop2 = Lpop(&stk);
			pop1 = Lpop(&stk);
			switch (tok)
			{
			case '*':
				Lpush(&stk, pop1 * pop2);
				break;
			case '/':
				Lpush(&stk, pop1 / pop2);
				break;
			case '+':
				Lpush(&stk, pop1 + pop2);
				break;
			case '-':
				Lpush(&stk, pop1 - pop2);
				break;
			}
		}
	}
	printf("%.2f\n", Lpop(&stk));

}


int main() {
	int val;
	char exp[5001];
	int exp2[26];
	scanf("%d", &TC);
	scanf("%s", exp);
	for (int i = 0; i < TC; i++) {
		scanf("%d", &val);
		exp2[i] = val;
	}

	ConvExp(exp,exp2);
}