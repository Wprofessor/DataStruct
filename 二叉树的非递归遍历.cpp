#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
typedef char datatype;
typedef struct node {
	datatype info;
	struct node *lchild,*rchild;
} node,*treenode;
treenode creatTree() {
	char ch;
	treenode t;
	cin>>ch;
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
//ǰ��ǵݹ����
void perorder(treenode t) {
	treenode data[MAXSIZE]; //����ջ�ṹ
	int top = 0;
	while(t || top != 0) {
		if(t) {
			cout<<t->info;
			data[top++] = t;
			t = t->lchild;
		} else {
			top--;
			t = data[top];
			t = t->rchild;
		}
	}
	cout<<endl;
}
//����ǵݹ����
void inorder(treenode t) {
	treenode data[MAXSIZE];
	int top = 0;
	while(t || top != 0) {
		if(t) {
			data[top++] = t;
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
//����ǵݹ����
void postorder(treenode t) {
	treenode data[MAXSIZE];
	int top = 0;
	int tag[MAXSIZE]; 	//�������
	memset(tag,0,sizeof(tag));
	while(t || top != 0) {
		if(t) {
			data[top++] = t;
			t = t->lchild;
		} else {
			if(tag[top-1] == 1) {
				top--;
				t = data[top];
				cout<<t->info;
				tag[top] = 0;
				t = NULL;
			} else {
				tag[top-1] = 1;
				t = data[top-1];
				t = t->rchild;
			}
		}
	}
	cout<<endl; 
}
int main() {
	treenode t;
	t = creatTree();
	perorder(t);
	inorder(t);
	postorder(t);
	return 0;
}
