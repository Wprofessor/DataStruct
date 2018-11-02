#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
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
		t->lchild = creatTree();            //ǰ������ݹ齨��
		t->rchild = creatTree();
	}
	return t;                               //���ظ��ڵ�
}
void perorder1(treenode t) {				//ǰ������ķǵݹ�ʵ��
	treenode data[MAXSIZE];
	int top = 0;
	while(t || top != 0) {
		if(t) {
			cout<<t->info;
			data[top] = t;
			top++;
			t = t->lchild;
		} else {
			top--;
			t = data[top];
			t = t->rchild;
		}
	}
	cout<<endl;
}
void inorder1(treenode t) {					//��������ķǵݹ�ʵ��
	treenode data[MAXSIZE];
	int top = 0;
	while(t || top != 0) {
		if(t) {
			data[top] = t;
			top++;
			t = t->lchild;
		} else {
			top--;
			t = data[top];
			cout<<t->info;
			t = t->rchild;
		}
	}
	cout<<endl;
}
void postorder1(treenode t) {				//��������ķǵݹ�ʵ��
	treenode data[MAXSIZE];
	int sign[MAXSIZE];                      //�������
//	memset(sign,-1,sizeof(sign));			//����������ʼ��Ϊ-1
	int top = 0;
	while(t || top != 0) {
		if(t) {
			data[top] = t;
			sign[top] = 0;
			top++;
			t = t->lchild;
		} else if(sign[top-1] == 1) {
			top--;
			t = data[top];
			cout<<t->info;
			t = NULL;                       //���ʺ�Ҫ�ÿգ���ֹ��ѭ�� 
		} else if(sign[top-1] == 0) {
			t = data[top-1];
			sign[top-1] = 1;
			t = t->rchild;
		} else {
			t == NULL;
		}
	}
	cout<<endl;
}
int main() {
	treenode t;
	t = creatTree();
	perorder1(t);
	inorder1(t);
	postorder1(t);
	return 0;
}

