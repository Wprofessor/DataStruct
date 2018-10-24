#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef int datatype;
typedef struct dlink_node {
	datatype info;
	struct dlink_node *llink,*rlink;
} node;
node *init() {
	return NULL;
}
void display(node *head) {
	node *q;
	q = head;
	if(!q)
		cout<<"表空"<<endl;
	else {
		while(q) {
			cout<<q->info<<endl;
			q = q->rlink;
		}
	}
}
node *find(node *head,int i) {
	if(i < 1) {                                 //head为第一个节点 ,为insert做铺垫
		cout<<"查询错误"<<endl;
		return NULL;
	}
	node *p;
	p = head;
	int ok = 1;
	while(p && ok != i) {
		p = p->rlink;
		ok++;
	}
	if(!p) {
		cout<<"查询错误"<<endl;
		return NULL;
	}
	return p;
}
//在第i个节点后插入
node *insert(node *head,datatype x,int i) {
	node *p,*q;
	p = (node*)malloc(sizeof(node));
	p->info = x;
	if(i == 0) {
		p->llink = NULL;
		p->rlink = head;
		if(!head) {
			head = p;
		} else {
			head->llink = p;
			head = p;
		}
		return head;
	}
	q = find(head,i);
	if(!q) {
		cout<<"插入错误"<<endl;
		free(p);
		return NULL;
	}
	if(q->rlink == NULL) {
		p->rlink = q->rlink;
		p->llink = q;
		q->rlink = p;
	} else {
		p->rlink = q->rlink;
		p->llink = q;
		q->rlink->llink = p;
		p->llink = q;
	}
	return head;
}
node *del(node *head,datatype x) {
	node *q;
	if(!head) {
		cout<<"表空"<<endl;
		return head;
	}
	q = head;
	while(q && q->info != x) q = q->rlink;
	if(!q) {
		cout<<"删除失败"<<endl;
		return head;
	}
	if(q == head && head->rlink) {
		head = head->rlink;
		head->llink = NULL;
		free(q);
		return head;
	}
	if(q == head && !head->rlink) {
		free(q);
		return NULL;
	} else {
		if(!q->rlink) {
			q->llink->rlink = NULL;
			free(q);
			return head;
		} else {
			q->rlink = q->llink->rlink;
			q->llink = q->rlink->llink;
			free(q);
			return head;
		}
	}
}
int main() {
	node *head;
	head = init();
	head = insert(head,0,0);
	head = insert(head,1,1);
	head = insert(head,2,2);
	head = insert(head,3,3);
	head = insert(head,4,4);
	head = insert(head,5,5);
	display(head);
	return 0;
}
