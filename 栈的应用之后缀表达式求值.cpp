#include<stdio.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
double change(char f[],int *pos) {      //pos是开始搜索的位置，会一直发生改变
	double x=0.0;
	int val=0;
	while(f[(*pos)]>'0' && f[(*pos)]<'9') {
		x = x*10.0 + (f[(*pos)]-'0');
		(*pos)++;
	}
	if(f[(*pos)]=='.') {
		(*pos)++;
		while(f[(*pos)]>'0' && f[(*pos)]<'9') {
			x = x*10.0 + (f[(*pos)]-'0');
			(*pos)++;
			val++;
		}
	}
	while(val > 0) {
		x /=10;
		val--;
	}
	return x;
}
double endget(char f[]) {
	int len=strlen(f);
	double t = 0.0;
	double x1,x2;
	int pos=0;
	double stack[MAXSIZE];
	int top = 0;
	while( pos < len ) {   //退出标志
		if( f[pos] > '0' && f[pos] < '9' ) {
			t = change( f , &pos );
			stack[top] = t;
			top++;
		} else if( f[pos] == ' ' ) {
			pos++;
		} else if( f[pos] == '+' ) {
			pos++;
			x1 = stack[--top];
			x2 = stack[--top];
			stack[top] = x1 + x2;
			top++;
		} else if( f[pos] == '-' ) {
			pos++;
			x1 = stack[--top];
			x2 = stack[--top];
			stack[top] = x2 - x1;
			top++;
		} else if( f[pos] == '*' ) {
			pos++;
			x1 = stack[--top];
			x2 = stack[--top];
			stack[top] = x2 * x1;
			top++;
		} else if( f[pos] == '/' ) {
			pos++;
			x1 = stack[--top];
			x2 = stack[--top];
			stack[top] = x2 / x1;
			top++;
		}
	}
	return stack[0];
}
int main() {
	cout<<endget("77.78  222+");
	return 0;
}
