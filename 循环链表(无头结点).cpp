#include<stdio.h>
#include<string.h>
#include<iostream>
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
node *real( node *head) {       //�õ����һ���ڵ�
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
		cout<<"���"<<endl;
	} else {
		node *p;                    //�������ֻ��һ���ڵ����� 
		cout<<head->info<<endl;
		p = head->next;
		while(p != head){
			cout<<p->info<<endl;
			p = p->next;
		}
	}
}

int main() {

	return 0;
}
