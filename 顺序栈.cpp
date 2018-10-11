#include<stdio.h>
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int datatype;
typedef struct {
	datatype a[MAXSIZE];
	int top;
} sequence_stack;
void init(sequence_stack *sta) {
	sta->top=0;
}
int empty(sequence_stack sta) {
	return sta.top?0:1;
}
datatype read(sequence_stack sta) {
	if(empty(sta)) {
		cout<<"Õ»ÊÇ¿ÕµÄ"<<endl;
		exit(1) ;
	} else {
		return sta.a[sta.top-1];
	}
}
void push(sequence_stack *sta,datatype x) {
	if(sta->top==MAXSIZE) {
		cout<<"Õ»Âú"<<endl;
		return ;
	} else {
		sta->a[sta->top]=x;
		sta->top++;
	}
}
void pop(sequence_stack *sta) {
	if(sta->top==0) {
		cout<<"¿ÕÕ»"<<endl;
		exit(1);
	}
	sta->top--;
}
int main() {
	sequence_stack sta;
	init(&sta);
	push(&sta,0);
	pop(&sta);
	cout<<"emmm"<<endl; 
	push(&sta,1);
	cout<<read(sta)<<endl;
	push(&sta,2);
	cout<<read(sta)<<endl;
	push(&sta,3);
	cout<<read(sta)<<endl;
	push(&sta,4);
	cout<<read(sta)<<endl;
	return 0;
}
