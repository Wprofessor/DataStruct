#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<stdlib.h>
using namespace std;
typedef int datatype;
typedef struct Dlink {
	int info;
	struct Dlink *next;
} link;
link *init() {
	link *head;
	head = (link*)malloc(sizeof(link));
	head->next = NULL;
	return head;
}
link *find( link *head,int x) {
	int val = 0;
	link *p;
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
link *insert( link *head,datatype x, int i) {   //i表示在第i个节点后插入
	link *p,*q;
	q = find(head,i);
	if( !q ) {
		cout<<"插入位置有误，请重新插入"<<endl;
		return head;
	}
	p = (link*)malloc(sizeof(link));
	p->info = x;
	p->next = q->next;
	q->next = p;
	return head;
}
link* reserve(link *head) {
	link *q,*p,*pre;
	if(!head->next)
		return head;
		q = NULL;
	pre = head->next;
	head->next = NULL;
	while(pre) {
		p = pre->next;
		pre->next = q;
		q = pre;
		pre = p;
	}
	head->next = q;
	return head;
}
void display( link *head ) {
	link *p = head->next;
	if( !p ) {
		cout<<"链表为空"<<endl;
	} else
		while( p ) {
			cout<<p->info<<endl;
			p = p->next;
		}
}
int main() {
	link *head;
	head = init();
	head = insert(head,0,0);
	head = insert(head,1,1);
	head = insert(head,2,2);
	head = insert(head,3,3);
	head = insert(head,4,4);
	display(head);
	head = reserve(head);
	display(head);
	return 0;
}
