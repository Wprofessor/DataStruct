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
		while(p != head){
			cout<<p->info<<endl;
			p = p->next;
		}
	}
}

int main() {

	return 0;
}
