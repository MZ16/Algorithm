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
	/*init�Լ��� �ۿ� ���������ϱ� ���� Ʋ����
	TC Ŭ�����Ҷ����� head�� ���Ž�������ϴµ� �ʱ�ȭ�Լ��� �ۿ��־ �׷���*/
	
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
	
/*��ȣ�� ¦�� ������ ������ YES, �ƴϸ� NO�� ���
* '('�� �Է��ϸ� PUSH, ')'�� ������ POP�� ���� */

/*����ؾ��� ���� 2���� 
* 1. Push�� pop�� ���� ���ƾ���
* 2. ���ÿ� 1���� �ڷᰡ �ִµ� 2���� POP�� �Ѱ��� 1���� �´��� NO�� ���
* //Push�� Pop�� ȣ�� Ƚ���� Push>=Pop�� ��� �����ؾߵ� */

/* 3. 2���� ������ �ذ��ϱ����� Push>=Pop�� ��������������� rock�̶�� ������ 1���� 0���� �������༭
*	 �Է��� ���� ���� �Ŀ� ����� �����ϰ� �ڵ带 ���� */