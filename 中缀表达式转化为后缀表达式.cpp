#include<stdio.h>
#include<string.h>
#include<iostream>
#define MAXSIZE 100
using namespace std;
int is_operation(char op) { //�ж��Ƿ��������
	switch(op) {
		case '*':
		case '/':
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}
int priority(char op) {  //���ַ��ŵ����ȼ�
	switch(op) {
		case '!':
			return -1;
		case '+':
		case '-':
			return 1;
		case '(':
			return 0;
		case '*':
		case '/':
			return 2;
		default:
			return -1;
	}
}
void transform(char e[],char f[]) {
	char opst[MAXSIZE];        //�������ջ 
	int top = 0;
	opst[0] = '!';             //��ʼ����һ���ַ�Ϊ���ȼ���͵� 
	top++;
	int len = strlen(e);
	int i = 0;
	int j = 0;
	while( i < len ) {
		if( e[i] >= '0' && e[i] <= '9' || e[i] == '.') {
			f[j++] = e[i];
		} else if( e[i] == '(' ) {
			opst[top] = e[i];
			top++;
		} else if( e[i] == ')' ) {
			int ok = top - 1;      //��ǵ�ǰ��ջ��Ԫ��
			while( opst[ok] != '(' ) {
				f[j++] = opst[--top];
				ok = top - 1;
			}
			top--;  //ʹ��'('��ջ
		} else if( is_operation(e[i]) ) {
			f[j++] = ' ';
			while( priority( e[i] ) <= priority(opst[top - 1] ))
				f[j++] = opst[--top];
			opst[top] = e[i];
			top++;
		}
		i++;
	}
	int val = top - 1;
	while( val > 0 ) {   //���˲���ջ��һ��Ԫ���������������
		f[j++] = opst[val];
		val--;
	}
}
int main() {
	char e[MAXSIZE];
	char f[MAXSIZE];
	cin>>e;
	transform( e,f );
	cout<<f<<endl;
	return 0;
}
