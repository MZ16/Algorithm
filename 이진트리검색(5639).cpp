#include <stdio.h>
#include <stdlib.h>

typedef int BTData;
typedef struct _bTree {
	BTData data;
	struct _bTree* left;
	struct _bTree* right;
}BTreeNode;

BTreeNode* MakeBTreeNode(BTData data) {
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
typedef void VisitFuncPtr(BTData data);

BTreeNode* BTInsert(BTreeNode* bt, BTData data) {
	if (bt == NULL) {
		bt = MakeBTreeNode(data);
		return bt;
	}
	else if (data < bt->data) {
		bt->left = BTInsert(bt->left, data);
	}
	else bt->right = BTInsert(bt->right, data);
	return bt;
}

void PostOrderTraverse(BTreeNode* bt) {
	if (bt == NULL)return;
	PostOrderTraverse(bt->left);
	PostOrderTraverse(bt->right);
	printf("%d\n", bt->data);
}

int main() {
	BTreeNode* bt=NULL;
	
	int val;
	while ((scanf("%d", &val) != EOF)) {
		bt=BTInsert(bt, val);
	}
	PostOrderTraverse(bt);

	return 0;
}
