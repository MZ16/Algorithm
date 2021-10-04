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

/*스택 명령어가 실행되면 문자열을 비교해 해당 스택 명령어의 결과를 출력함
* switch는 '문자'의 비교이기때문에 strcmp로 문자열을 비교해줌
* strcmp는 c1과 c2가 같을경우 0을 반환 아니면 1이상의 수를 반환하기때문에 if문으로 비교 시 !를 붙임
*/