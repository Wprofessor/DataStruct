#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
using namespace std;
typedef int datatype;
typedef struct link {
	datatype info;
	struct link *next;
} node;
node *init() {
	node *head;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	return head;
}
void display( node *head ) {
	node *p = head->next;
	if( !p ) {
		cout<<"链表为空"<<endl;
	} else
		while( p ) {
			cout<<p->info<<endl;
			p = p->next;
		}
}
node *find( node *head,int x) {
	int val = 0;
	node *p;
	p = head;
	if( x < 0 ) {                     //查找的位置太小
		cout<<"查询有误"<<endl;
		return NULL;
	}
	while( p && val != x ) {
		p = p->next;
		val++;
	}
	if(val < x) {                    //查找的位置太大
		cout<<"查询有误"<<endl;
		return NULL;
	} else
		return p;
}
node *insert( node *head,datatype x, int i) {   //i表示在第i个节点后插入
	node *p,*q;
	q = find(head,i);
	if( !q ) {
		cout<<"插入位置有误，请重新插入"<<endl;
		return head;
	}
	p = (node*)malloc(sizeof(node));
	p->info = x;
	p->next = q->next;
	q->next = p;
	return head;
}
node *del( node *head,datatype x) {
	node *p,*q;
	p = head;
	while( p ) {
		q = p;
		p = p->next;
		if( p->info == x ) {
			q->next = p->next;
			free(p);
			return head;
		}
	}
	return head;
}
int main() {
	node *head;
	head = init();
	head = insert(head,0,0);
	head = insert(head,1,1);
	head = insert(head,2,2);
	head = insert(head,3,3);
	head = insert(head,4,4);
	head = del(head,1);
	display(head);
	return 0;
}
