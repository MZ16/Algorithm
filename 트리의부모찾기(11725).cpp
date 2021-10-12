#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* left;
	struct _node* right;
}BTreeNode;

BTreeNode* MakeTreeNode(int data) {
	BTreeNode* bt = (BTreeNode*)malloc(sizeof(BTreeNode));
	bt->data = data;
	bt->left = NULL;
	bt->right = NULL;
	return bt;
}

void SetData(BTreeNode* bt, int data) {

}

BTreeNode* SearchBTree(BTreeNode* bt, int data) {
	if(bt!=NULL){
		if (bt->data == data)return bt;
		else {
			BTreeNode* bt2 = SearchBTree(bt->left, data);
			if (bt2 != NULL)return bt2;
			else return SearchBTree(bt->right, data);
		}
	}
	return NULL;
}
