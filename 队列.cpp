#include<stdio.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
typedef int datatype;
typedef struct {
	datatype a[MAXSIZE];
	int front;
	int real;
} sequence_queue;
void init( sequence_queue *q ) {
	q->front = q->real = 0;
}
int empty(sequence_queue q) {
	return ( q.front == q.real )?1:0;
}
void display( sequence_queue q ) {
	if( empty(q) ) {
		cout<<"队列为空"<<endl;
	} else {
		for( int i = q.front; i < q.real ; i++ ) {
			cout<<q.a[i]<<" ";
		}
	}
}
datatype get( sequence_queue q ) {
	if( empty(q) ) {
		cout<<"队列为空"<<endl;
		exit(1);
	} else {
		return q.a[q.front];
	}
}
void insert( sequence_queue *q, datatype x) {
	if( q->real == MAXSIZE ) {
		cout<<"队列已满"<<endl;
	} else {
		q->a[q->real] = x;
		q->real++;
	}
}
void del(sequence_queue *q) {
	if( q->front == q->real ) {
		cout<<"队列为空"<<endl;
	} else {
		q->front++;
	}
}
int main() {
	sequence_queue q;
	init(&q);
	display(q);
	return 0;
}
