#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct _node {
	struct _node* prev;
	char data;
}Node;

typedef struct _stk {
	Node* head;
}Lstk;

void Linit(Lstk* stk) {
	stk->head = NULL;
}

char Ltop(Lstk* stk) {
	return stk->head->data;
}

int Lempty(Lstk* stk) {
	if (stk->head == NULL) return 1;
	return 0;
}

void Lpush(Lstk* stk, char val) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = val;
		newNode->prev = stk->head;
		stk->head = newNode;
}

void Lpop(Lstk* stk) {
	char rdata;
	Node* rNode;

	rNode = stk->head;
	rdata = stk->head->data;
	stk->head = stk->head->prev;
	free(rNode);

}

int main() {
	Lstk stk;
	Linit(&stk);
	char input[30];
	int temp = 1;
	int result = 0;
	bool rock = 0;
	scanf("%s", &input);
	int len = strlen(input);

	for (int i = 0; i < len; i++) {
		//temp 셋팅
		if (input[i] == '(') {
			temp *= 2;
			Lpush(&stk, input[i]);
		}
		else if (input[i] == '[') {
			temp *= 3;
			Lpush(&stk, input[i]);
		}
		//안되는 조건
		else if (input[i] == ')' && (Lempty(&stk) || Ltop(&stk) != '(')) {
			rock = 1;
			break;
		}
		else if (input[i] == ']' && (Lempty(&stk) || Ltop(&stk) != '[')) {
			rock = 1;
			break;
		}
		
		// 되는 조건
		else if (input[i] == ')') {
			if (input[i - 1] == '(') result += temp; // 중요
			temp /= 2;
			Lpop(&stk);
		}
		else if (input[i] == ']') {
			if (input[i - 1] == '[') result += temp;
			temp /= 3;
			Lpop(&stk);
		}
	}
	if (!Lempty(&stk) || rock == 1)printf("0");
	else printf("%d", result);

	return 0;
}

/*
* 1. '('와 '[']일때는 temp*=2, tmep*=3을 해줘서 곱셈을 처리해줌
* 
* 2. ')'와 ']'는 pop의 조건, 우선적으론 Pop을 할수없을 경우부터 해준다.(연산횟수를 줄이기 위함)
*	1). ')'일때 Top이 '('가 아니거나 스택이 비었을경우 이미 잘못된 식임으로 더이상 연산이 무의미함, 
*		그래서 bool타입 대체변수인 rock을 1로 바꾸고 break를 사용해 반복문을 탈출
*	2) ']'일때도 위와 마찬가지임
* 
* 3.')'와 ']'는 pop의 조건, Pop의 조건이 성립할 경우 
	1). input[i]==')'일때 input[i-1]이 '('라면 result에 temp를 저장한 후 temp/2를 해줌
		//temp를 나누는것은 해당 괄호의 연산이 끝났음으로 이전값으로 돌리기 위함
	

	([]())란 괄호가 있다면 수식은 2(3+2)이다. 앞의 2는 괄호안에 모두 분배해야함으로
	이것을 풀어쓰면 (2*3) + (2*2) 이다. 
	그렇다면 ([]에서 pop의조건인 ']'를 만났으니 '['를 Pop해줌으로써 (2*3)의 연산결과를 result에 저장해주고
	해당 괄호의 값인 3을 나누어 모두 분배해야하는 값 2를 찾는다.
	그러면 남은 수식은 ()), '('를 푸쉬하면서 temp=2*2가 된다. 위와 마찬가지로 닫는괄호를 만나며 result에 저장되고
	마지막 닫는괄호는 input[i-1]=='('조건이 성립하지않아 temp/2와 pop만 해주고 result연산은 하지않는다.
	결국 나누면서 하는 이유는 괄호 안에 있는값에 분배하며 연산을 하기때문에 분배해야하는 값을 기억하기 위함이라
	볼 수 있다.
	
	 
	앞의 
*/