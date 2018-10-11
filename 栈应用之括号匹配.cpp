#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define MAXSIZE 100
typedef int datatype;
typedef struct {
	char a[MAXSIZE];
	int top;
} sequence_stack;
void init(sequence_stack *sta) {
	sta->top=0;
}
int empty(sequence_stack sta) {
	return sta.top?0:1;
}
char read(sequence_stack sta) {
	if(empty(sta)) {
		cout<<"¿ÕÕ»"<<endl;
		exit(1) ;
	} else {
		return sta.a[sta.top-1];
	}
}
void push(sequence_stack *sta,char x) {
	if(sta->top==MAXSIZE) {
		cout<<"Õ»Âú"<<endl;
		exit(1);
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
int Kuohaopipei(char *c) {
	sequence_stack sta;
	init(&sta);
	int len=strlen(c);
	int i=0;
	while(i<len) {
		switch(c[i]) {
			case '(':
			case '[':
			case '{': push(&sta,c[i]); break;
			case ')': {
				if(!empty(sta)&&read(sta)=='(') {
					pop(&sta);
					break;
				} else
					return 0;
			}
			case ']': {
				if(!empty(sta)&&read(sta)=='[') {
					pop(&sta);
					break;
				} else
					return 0;
			}
			case '}': {
				if(!empty(sta)&&read(sta)=='{') {
					pop(&sta);
					break;
				} else
					return 0;
			}
		}
		i++;
	}
	return empty(sta); 
}
int main() {
//	sequence_stack sta;
//	init(&sta);
//	push(&sta,'(');
//	cout<<read(sta);
	char c[MAXSIZE];
	cin>>c;
	int ok = Kuohaopipei(c);
	cout<<ok<<endl;
	return 0;
}
