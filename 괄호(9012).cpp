#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int Size = 0;
typedef struct _node {
	struct _node* prev;
	char data;
}Node;

typedef struct _stack {
	Node* head;
}LStk;

void Init(LStk* stk) {
	stk->head = NULL;
}

int LEmpty(LStk *stk) {
	if (!stk->head == NULL)return FALSE;
	else if(stk->head==NULL) return TRUE;
}
void LPush(LStk* stk, char data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = stk->head;
	stk->head = newNode;
}

int LPop(LStk *stk) {
	Node* rNode;
	if (LEmpty(stk)) {
		return 0;
	}
	else {
		rNode = stk->head;
		stk->head = stk->head->prev;
		free(rNode);
		return 1;
	}
}

int main() {
	LStk stk;
	int TC;
	int rock = 1;
	char ch[50];
	/*init함수가 밖에 빠져있으니까 값이 틀려짐
	TC 클리어할때마다 head를 갱신시켜줘야하는데 초기화함수가 밖에있어서 그런듯*/
	
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		Init(&stk);
		scanf("%s", &ch);
		int len = strlen(ch);
		//printf("%d\n", len);
		for (int i = 0; i < len; i++) {
			//printf("%c", ch[i]);
			if (ch[i] == '(')LPush(&stk, '(');
			if (ch[i] == ')') {
				if (!LPop(&stk)) {
					rock = 0;
				}
			}
		}//printf("\n");
		if (LEmpty(&stk) && rock == 1)printf("YES\n");
		else if (!LEmpty(&stk) || rock == 0) printf("NO\n");
		rock = 1;
		//free(&stk);
		}
		//printf("%d", len);
		/*
		getchar();
		char ch;
		while ((ch = getchar()) != '\n') {
			//printf("%c ", ch);
			*/
	return 0;
	}
	
/*괄호의 짝과 순서가 맞으면 YES, 아니면 NO를 출력
* '('를 입력하면 PUSH, ')'를 만나면 POP을 해줌 */

/*고려해야할 사항 2가지 
* 1. Push와 pop의 수가 같아야함
* 2. 스택에 1개의 자료가 있는데 2번의 POP을 한경우는 1번이 맞더라도 NO를 출력
* //Push와 Pop의 호출 횟수가 Push>=Pop이 계속 성립해야됨 */

/* 3. 2번의 문제를 해결하기위해 Push>=Pop이 성립하지않을경우 rock이라는 변수를 1에서 0으로 변경해줘서
*	 입력을 전부 받은 후에 결과를 도출하게 코드를 만듬 */