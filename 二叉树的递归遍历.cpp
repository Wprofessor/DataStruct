#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
typedef char datatype;
typedef struct node {
	datatype info;
	struct node *lchild,*rchild;
} node,*treenode;
treenode creatTree() {
	char ch;
	treenode t;
	ch = getchar();
	if(ch == '#')                            //空子树用#号代替
		t = NULL;
	else {
		t = (node *)malloc(sizeof(node));
		t->info = ch;
		t->lchild = creatTree();              //前序遍历递归建树
		t->rchild = creatTree();
	}
	return t;                               //返回根节点
}
void preorder(treenode t) {    				//前序遍历的递归实现
	if(t) {
		cout<<t->info;
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
void inorder(treenode t) {					//中序遍历的递归实现
	if(t) {
		inorder(t->lchild);
		cout<<t->info;
		inorder(t->rchild);
	}
}
void postorder(treenode t) {				//后序遍历的递归实现
	if(t) {
		postorder(t->lchild);
		postorder(t->rchild);
		cout<<t->info;
	} 
}
int main() {
	treenode t;
	t = creatTree();
	preorder(t);
	cout<<endl;
	inorder(t);
	cout<<endl;
	postorder(t);
	cout<<endl;
	return 0;
}

