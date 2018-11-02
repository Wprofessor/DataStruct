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
	if(ch == '#')                            //��������#�Ŵ���
		t = NULL;
	else {
		t = (node *)malloc(sizeof(node));
		t->info = ch;
		t->lchild = creatTree();              //ǰ������ݹ齨��
		t->rchild = creatTree();
	}
	return t;                               //���ظ��ڵ�
}
void preorder(treenode t) {    				//ǰ������ĵݹ�ʵ��
	if(t) {
		cout<<t->info;
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
void inorder(treenode t) {					//��������ĵݹ�ʵ��
	if(t) {
		inorder(t->lchild);
		cout<<t->info;
		inorder(t->rchild);
	}
}
void postorder(treenode t) {				//��������ĵݹ�ʵ��
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

