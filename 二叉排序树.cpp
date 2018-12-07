#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define maxsize 1000
using namespace std;
typedef int datatype;
typedef struct node {
	datatype key;
	struct node *lchild,*rchild;
} bsnode;
typedef bsnode *bstree;
//�ǵݹ����
bstree bssearch1(bstree *t,datatype x) {
	bstree p;
	p = *t;
	while(p) {
		if(p->key == x)
			return p;
		p = x < p->key ? p->lchild : p->rchild;
	}
	return NULL;
}
//�ݹ����
bstree bssearch2(bstree t,datatype x) {
	if(t == NULL || x == t->key)
		return t;
	if(x < t->key)
		return bssearch2(t->lchild,x);
	else
		return bssearch2(t->rchild,x);
}
//�����������Ĳ����㷨
void InsertBstree(bstree *t,datatype x) {		//ע�⣺�����Ƕ���ָ�룬��Ϊ���洴����ʱ���õ��˲��������Ҫֱ���޸ĵ�ַ 
	if(bssearch1(t,x))
		return ;
	else {
		bstree f,p;
		f = NULL;
		p = *t;
		while(p) {
			f = p;			//f����Ҫ�����λ��
			p = x < p->key ? p->lchild : p->rchild;
		}
		p = (bstree)malloc(sizeof(bsnode));
		p->key = x;
		p->lchild = p->rchild = NULL;
		if(*t == NULL) {
			*t = p;
		} else {
			if(x < f->key) {
				f->lchild = p;
				//cout<<f->lchild->key<<endl;
			} else {
				f->rchild = p;
				//cout<<f->rchild->key<<endl;
			}
		}
	}
}
bstree CreatBstree() {
	bstree t = NULL;
	datatype key;
	cout<<"������һ����-1Ϊ������־������"<<endl;
	cin>>key;
	while(key != -1) {
		InsertBstree(&t,key);
		cin>>key;
	}
	return t;
}
void display(bstree t) {
	if(t) {
		display(t->lchild);
		cout<<t->key<<endl;
		display(t->rchild);
	}
}
int main() {
	bstree t,p;
	t = CreatBstree();
	display(t);
	p = bssearch1(&t,2);
	if(!p)
		cout<<"û�ҵ�"<<endl;
	else
		cout<<p->key<<endl;
	return 0;
}
