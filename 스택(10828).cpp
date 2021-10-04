#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int Size;
typedef struct _node {
	struct _node* prev;
	int data;
}Node;
typedef struct _list {
	Node* head;
}List;

void Init(List *list) {
	list->head = NULL;
	
}

int LEmpty(List* list) {
	if (list->head == NULL) return TRUE;
	else return FALSE;
}

void LPush(List* list, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = list->head;
	list->head = newNode;
	Size++;
}

int LPop(List* list) {
	Node* rNode;
	int rData;
	if (LEmpty(list)) {
		return -1;
	}
	else {
		rData = list->head->data;
		rNode = list->head;
		list->head = list->head->prev;
		Size--;
		free(rNode);
		return rData;
	}	
}

int LSize(List *list) {
	return Size;
}

int LTop(List *list) {
	if (!LEmpty(list)) return list->head->data;
	else return -1;
}

int main() {
	List list;
	Init(&list);
	int TC,num;
	char ch[10];
	
	
	scanf("%d", &TC);
	
	for (int i = 0; i < TC; i++) {
		scanf(" %s", &ch);

		//printf("%s\n", ch);
		
		if (!strcmp(ch,"push")) {
			scanf("%d", &num);
			LPush(&list, num);
		}
		
		else if (!strcmp(ch,"pop")) {
			printf("%d\n", LPop(&list));
		}
		else if (!strcmp(ch, "size")) {
			printf("%d\n", LSize(&list));
		}
		else if (!strcmp(ch, "empty")) {
			printf("%d\n", LEmpty(&list));
		}
		else if (!strcmp(ch, "top")) {
			printf("%d\n", LTop(&list));
		}
	}

	return 0;
}

/*���� ��ɾ ����Ǹ� ���ڿ��� ���� �ش� ���� ��ɾ��� ����� �����
* switch�� '����'�� ���̱⶧���� strcmp�� ���ڿ��� ������
* strcmp�� c1�� c2�� ������� 0�� ��ȯ �ƴϸ� 1�̻��� ���� ��ȯ�ϱ⶧���� if������ �� �� !�� ����
*/