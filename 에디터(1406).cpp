#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	char data;
	struct _node* prev;
	struct _node* next;
}Node;


int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = ' ';
	head->prev = head->next = NULL;
	Node* cur = head;

	int N;
	char ch;
	
	while ((ch = getchar()) != '\n') { // ch=getchar() 쓸때 묶어줘야됨 ㅠㅠ
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = ch;
		newNode->next = NULL;
		newNode->prev = cur;
		cur->next = newNode;
		cur = cur->next;
	}
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char op;
		scanf(" %c", &op);
		//scanf에 공백을 주면 개행을 무시함
		//scanf("%d.%d",&a,&b) <-이렇게 하면 점이 무시되고 정수 두개로 입력받아짐
		

		switch (op) {
		case 'L' : // 커서를 왼쪽으로 이동
		{
			if (cur->prev != NULL) { //런타임에러 이유(아까 실수로 지움..)
				cur = cur->prev;
			}			
			break;
		}
			
		case 'D' : // 커서를 오른쪽으로 이동
		{
			if (cur->next != NULL) {
				cur = cur->next;
			}			
			break;
		}			

		case 'B': {
			if (cur->prev == NULL)continue;
			Node* del = (Node*)malloc(sizeof(Node));
			del = cur;
			cur = cur->prev;
			if (del->next) { // 삭제노드 뒤에 값이 있다면
				del->next->prev = cur;
				cur->next = del->next;
				del->prev = NULL; // 얘는 연결 끊기
			}
			else // 마지막 노드
				cur->next = NULL;
			
			free(del);
			break;
		}
			

		case 'P' :// P는 커서 왼쪽에 추가한다지만 실질적으로 cur다음에 위치하면 됨
		{
			char c;
			scanf(" %c", &c); // 개행 무시
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = c;
			newNode->prev = cur;
			if (cur->next) {
				newNode->next = cur->next;
				cur->next->prev = newNode;
				
			}
			else {
				newNode->next = NULL;
			}
			cur->next = newNode;
			cur = cur->next; // cur위치 조정
		
			break;
		}			

		}

	}
	head = head->next;
	while (head) {
		printf("%c", head->data);
		head=head->next;
	}

}

//for (Node* now = head; now->next != NULL; now = now->next)

