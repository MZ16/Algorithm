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
	
	while ((ch = getchar()) != '\n') { // ch=getchar() ���� ������ߵ� �Ф�
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
		//scanf�� ������ �ָ� ������ ������
		//scanf("%d.%d",&a,&b) <-�̷��� �ϸ� ���� ���õǰ� ���� �ΰ��� �Է¹޾���
		

		switch (op) {
		case 'L' : // Ŀ���� �������� �̵�
		{
			if (cur->prev != NULL) { //��Ÿ�ӿ��� ����(�Ʊ� �Ǽ��� ����..)
				cur = cur->prev;
			}			
			break;
		}
			
		case 'D' : // Ŀ���� ���������� �̵�
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
			if (del->next) { // ������� �ڿ� ���� �ִٸ�
				del->next->prev = cur;
				cur->next = del->next;
				del->prev = NULL; // ��� ���� ����
			}
			else // ������ ���
				cur->next = NULL;
			
			free(del);
			break;
		}
			

		case 'P' :// P�� Ŀ�� ���ʿ� �߰��Ѵ����� ���������� cur������ ��ġ�ϸ� ��
		{
			char c;
			scanf(" %c", &c); // ���� ����
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
			cur = cur->next; // cur��ġ ����
		
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

