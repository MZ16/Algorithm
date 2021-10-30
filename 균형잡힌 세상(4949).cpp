#include<iostream>
#include <string>
#include<stack>
using namespace std;

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
	Lstk v;
	
	int rock = 0;
	string s;
	while (1) {		
		Linit(&v);
		getline(cin, s);
		if (s[0] == '.')break;	
		
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[')Lpush(&v, s[i]);

			else if (s[i] == ')')
				if(!Lempty(&v) && Ltop(&v) == '(') {
				Lpop(&v);
				}
				else rock = 1;
			else if (s[i] == ']')
				if(!Lempty(&v) && Ltop(&v) == '[') {
				Lpop(&v);
				}else rock = 1;
		
			
		}

		if (Lempty(&v)&&rock==0)printf("yes\n");
		else printf("no\n");	
		while (!Lempty(&v))Lpop(&v); rock = 0;
		
	}

	return 0;
}