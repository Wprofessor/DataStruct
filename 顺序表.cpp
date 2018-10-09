#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int datatype;
typedef struct {
	datatype a[MAXSIZE];
	int size;
} sequence_list;
void init(sequence_list *silt) {
	silt->size = 0;
}
void append(sequence_list *silt,datatype x) {
	if(silt->size==MAXSIZE) {
		cout<<"表满"<<endl;
		exit(1);
	} else {
		silt->a[silt->size]=x;
		silt->size++;
	}
}
void display(sequence_list *silt) {
	if(silt->size==0) {
		cout<<"表空"<<endl;
	} else {
		for(int i=0; i<silt->size; i++) {
			cout<<silt->a[i]<<" ";
		}
		cout<<endl;
	}
}
//判断表是否为空
int empty(sequence_list *silt) {
	return silt->size==0?1:0;
}
//查找位置
int find(sequence_list *silt,datatype x) {
	int count=0;
	while(count<silt->size) {
		if(silt->a[count]) {
			break;
		}
		count++;
	}
	if(count==silt->size)
		return -1;
	else
		return count;
}
//查找值
datatype get(sequence_list *silt,int i) {
	if(i < 0||i >= silt->size) {
		cout<<"无值"<<endl;
		exit(1);
	} else
		return silt->a[i];
}
//插入
void insert(sequence_list *silt,int pos,datatype x) {
	if(pos<0 || pos>silt->size) {
		cout<<"非法插入"<<endl;
		exit(1);
	} else if(silt->size == MAXSIZE) {
		cout<<"表满"<<endl;
		exit(1);
	} else {
		for(int i=silt->size; i>pos; i--) {
			silt->a[i]=silt->a[i-1];
		}
		silt->a[pos]=x;
		silt->size++;
	}
}
//删除
void delet(sequence_list *silt,int pos){
	if(pos<0 || pos>=silt->size){
		cout<<"非法操作"<<endl;
		exit(1);
	}
	for(int i=pos;i<silt->size;i++){
		silt->a[i]=silt->a[i+1];
	}
	silt->size--;
}
int main() {
	sequence_list silt;
	init(&silt);
	append(&silt,1);
	append(&silt,2);
	append(&silt,3);
	append(&silt,4);
	append(&silt,5);
	display(&silt);
	return 0;
}
