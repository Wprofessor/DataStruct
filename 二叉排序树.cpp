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
//非递归查找
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
//递归查找
bstree bssearch2(bstree t,datatype x) {
	if(t == NULL || x == t->key)
		return t;
	if(x < t->key)
		return bssearch2(t->lchild,x);
	else
		return bssearch2(t->rchild,x);
}
//二叉排序树的插入算法
void InsertBstree(bstree *t,datatype x) {		//注意：这里是二级指针，因为下面创建的时候用到了插入操作，要直接修改地址 
	if(bssearch1(t,x))
		return ;
	else {
		bstree f,p;
		f = NULL;
		p = *t;
		while(p) {
			f = p;			//f保存要插入的位置
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
	cout<<"请输入一个以-1为结束标志的序列"<<endl;
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
		cout<<"没找到"<<endl;
	else
		cout<<p->key<<endl;
	return 0;
}
