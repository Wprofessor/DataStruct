#include<stdio.h>
#include<iostream>
#include<stdlib.h> 
#include<string.h>
#define MAXSIZE 100
using namespace std;
typedef int datatype;
typedef struct node_stack {
	datatype info;
	struct node_stack *next;
} node;
node *init() {
	return NULL;
}
int empty(node *top) {
	return top?0:1;
}
void display(node *top) {
	node *p;
	p = top;
	if(!p){
		cout<<"Õ»¿Õ"<<endl;
	}
	while(p){
		cout<<p->info<<endl;
		p = p->next;
	} 
}
node *push(node *top,datatype x) {
	node *p;
	p = (node*)malloc(sizeof(node));
	p->info = x;
	p->next = top;
	top = p;
	return top;
}
node *pop(node *top) {
	node *q;
	if(!top){
		cout<<"¿ÕÕ»"<<endl;
		return NULL;
	}
	q = top;
	top = top->next;
	free(q);
	return top;
}
int main() {
	node *top;
	top = init();
	top = push(top,0);
	top = push(top,1);
	top = push(top,2);
	top = push(top,3);
	top = push(top,4);
	top = push(top,5);
	display(top);
	return 0;
}
