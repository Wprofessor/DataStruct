#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#define MAXSIZE 100
using namespace std;
typedef int datatype;
typedef struct link_node {
	datatype info;
	struct link_node *next;
} node;
node *init() {
	return NULL;
}
node *real( node *head) {       //得到最后一个节点
	node *p;
	if(!head)
		return NULL;
	else {
		p = head;
		if(p->next != head)
			p = p->next;
	}
	return p;
}
void display(node *head) {
	if(!head) {
		cout<<"表空"<<endl;
	} else {
		node *p;                    //避免出现只有一个节点的情况
		cout<<head->info<<endl;
		p = head->next;
		while(p != head) {
			cout<<p->info<<endl;
			p = p->next;
		}
	}
}
node *find(node *head,datatype x) {
	node *q;
	if(!head)
		return NULL;
	q = head->next;
	if(head->info == x)
		return head;
	while(q->next != head ) {
		if(q->info == x)
			return q;
		q = q->next;
	}
	return NULL;
}
node *insert(node *head,datatype x,int goal) {
	int count = 1;
	node *q,*p;
	q = (node*)malloc(sizeof(node));
	q->info = x;
	if(goal < 0) {
		cout<<"非法插入"<<endl;
		free(q);
		return head;
	}
	if(goal == 0 && !head) {
		q->next = q;
		head = q;
		return head;
	}
	if(goal > 0 && !head) {
		cout<<"非法插入"<<endl;
		free(q);
		return head;
	}
	if(goal == 0 && head) {
		p = head;
		q->next = p->next;
		p->next = q;
		return head;
	}
	p = head->next;
	while(p != head) {
		if(count == goal) {
			q->next = p->next;
			p->next = q;
			return head;
		}
		count++;
		p = p->next;
	}
	return head;
}
node *dele(node *head,datatype x) {
	node *q,*t;
	q = find(head,x);
	t = real(head);
	if(!q) {
		cout<<"删除错误"<<endl;
		return head;
	}
	if(head->info == x && head->next == head) {
		free(head);
		head = NULL;
		return head;
	}
	if(head->info == x){
		node *s;
		s=head;
		head = head->next;
		t->next = head;
		free(s);
		return head;
	}
	node *pre,*p;
	pre = head;
	p = head->next;
	while(p->info != x) {
		pre = p;
		p = p->next;
	}
	pre->next = q->next;
	free(q);
	return head;
}
int main() {
	node *head;
	head = init();
	head = insert(head,0,0);
	head = insert(head,1,0);
	head = dele(head,0);
	display(head);
	return 0;
}
