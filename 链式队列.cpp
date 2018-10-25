#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
using namespace std;
typedef int datatype;
typedef struct node_queue {
	datatype info;
	struct node_queue *next;
} node;
typedef struct {
	node *front,*real;
} queue;
queue *init() {
	queue *qu;
	qu = (queue *)malloc(sizeof(queue));
	qu->front = NULL;
	qu->real = NULL;
	return qu;
}
int empty(queue *qu) {
	return qu->front?0:1;
}
void display(queue *qu) {
	node *p;
	p = qu->front;
	if(!p) {
		cout<<"队列为空"<<endl;
	}
	while(p) {
		cout<<p->info<<endl;
		p = p->next;
	}
}
queue *insert(queue *qu,datatype x) {
	node *q;
	q = (node*)malloc(sizeof(node));
	q->info = x;
	q->next = NULL;
	if(qu->front == NULL) {
		qu->front = q;
		qu->real = q;
	} else {
		qu->real->next = q;
		qu->real = q;
	}
	return qu;
}
queue *dele(queue *qu) {
	node *q;
	q = qu->front;
	if(!q){
		cout<<"队列为空"<<endl;
		return qu;
	}
	qu->front = qu->front->next;
	free(q);
	if(!qu->front)
	qu->real = NULL;
	return qu; 
}
int main() {
	queue *qu;
	qu = init();
	qu = insert(qu,0);
	qu = insert(qu,1);
	qu = insert(qu,2);
	qu = insert(qu,3);
	qu = insert(qu,4);
	qu = insert(qu,5);
	display(qu);
	qu = dele(qu);
	qu = dele(qu);
	qu = dele(qu);
	qu = dele(qu);
	qu = dele(qu);
	qu = dele(qu);
	display(qu);
	return 0;
}
