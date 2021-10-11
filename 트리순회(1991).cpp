#include <stdio.h>
#include <stdlib.h>

typedef struct _bTreeNode {
	char data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeTreeNode(int data) {
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void SetData(BTreeNode* bt, int d1, int d2, int d3) {
	bt->data = d1;
	if (d2 != '.')bt->left = MakeTreeNode(d2);
	if (d3 != '.')bt->right = MakeTreeNode(d3);
}

BTreeNode* SearchTree(BTreeNode* bt, int data) {
	if (bt != NULL) {
		if (bt->data == data) return bt;
		else {
			BTreeNode* bt2 = SearchTree(bt->left, data);
			if (bt2 != NULL) return bt2;
			return SearchTree(bt->right, data);
		}
	}
	return NULL;
}

void InordefTraverse(BTreeNode* bt) { //중위 순회 ∧ 
	if (bt == NULL) return;

	InordefTraverse(bt->left);
	printf("%c", bt->data);
	InordefTraverse(bt->right);
}

void PreordefTraverse(BTreeNode* bt) { // 전위 순회 ＜
	if (bt == NULL) return;

	printf("%c", bt->data);
	PreordefTraverse(bt->left);
	PreordefTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt) { // 후위 순회 ＞
	if (bt == NULL) return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%c", bt->data);
}

int main() {
	int N;
	char ch[3];
	
	BTreeNode* bt = MakeTreeNode(NULL);
	BTreeNode* bt2;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%c %c %c", &ch[0], &ch[1], &ch[2]);
		getchar();
		bt2 = SearchTree(bt, ch[0]);
		if (bt2 != NULL) SetData(bt2, ch[0], ch[1], ch[2]);
		else SetData(bt, ch[0], ch[1], ch[2]);
		}
	PreordefTraverse(bt); printf("\n");
	InordefTraverse(bt); printf("\n");
	PostorderTraverse(bt); printf("\n");
	return 0;
	}

