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
		//temp ����
		if (input[i] == '(') {
			temp *= 2;
			Lpush(&stk, input[i]);
		}
		else if (input[i] == '[') {
			temp *= 3;
			Lpush(&stk, input[i]);
		}
		//�ȵǴ� ����
		else if (input[i] == ')' && (Lempty(&stk) || Ltop(&stk) != '(')) {
			rock = 1;
			break;
		}
		else if (input[i] == ']' && (Lempty(&stk) || Ltop(&stk) != '[')) {
			rock = 1;
			break;
		}
		
		// �Ǵ� ����
		else if (input[i] == ')') {
			if (input[i - 1] == '(') result += temp; // �߿�
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
* 1. '('�� '[']�϶��� temp*=2, tmep*=3�� ���༭ ������ ó������
* 
* 2. ')'�� ']'�� pop�� ����, �켱������ Pop�� �Ҽ����� ������ ���ش�.(����Ƚ���� ���̱� ����)
*	1). ')'�϶� Top�� '('�� �ƴϰų� ������ �������� �̹� �߸��� �������� ���̻� ������ ���ǹ���, 
*		�׷��� boolŸ�� ��ü������ rock�� 1�� �ٲٰ� break�� ����� �ݺ����� Ż��
*	2) ']'�϶��� ���� ����������
* 
* 3.')'�� ']'�� pop�� ����, Pop�� ������ ������ ��� 
	1). input[i]==')'�϶� input[i-1]�� '('��� result�� temp�� ������ �� temp/2�� ����
		//temp�� �����°��� �ش� ��ȣ�� ������ ���������� ���������� ������ ����
	

	([]())�� ��ȣ�� �ִٸ� ������ 2(3+2)�̴�. ���� 2�� ��ȣ�ȿ� ��� �й��ؾ�������
	�̰��� Ǯ��� (2*3) + (2*2) �̴�. 
	�׷��ٸ� ([]���� pop�������� ']'�� �������� '['�� Pop�������ν� (2*3)�� �������� result�� �������ְ�
	�ش� ��ȣ�� ���� 3�� ������ ��� �й��ؾ��ϴ� �� 2�� ã�´�.
	�׷��� ���� ������ ()), '('�� Ǫ���ϸ鼭 temp=2*2�� �ȴ�. ���� ���������� �ݴ°�ȣ�� ������ result�� ����ǰ�
	������ �ݴ°�ȣ�� input[i-1]=='('������ ���������ʾ� temp/2�� pop�� ���ְ� result������ �����ʴ´�.
	�ᱹ �����鼭 �ϴ� ������ ��ȣ �ȿ� �ִ°��� �й��ϸ� ������ �ϱ⶧���� �й��ؾ��ϴ� ���� ����ϱ� �����̶�
	�� �� �ִ�.
	
	 
	���� 
*/