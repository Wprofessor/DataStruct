#include<bits/stdc++.h>
using namespace std;
//关键字集合长度
#define MAX 6
//hash表长
#define Hashmax 5
int data[MAX];
typedef struct list {
	int key;	//键值
	struct list *next;
} node , *link;
//拉链法构造散列表
link hastab[Hashmax];
//求余法散列函数
int hash_mod(int key) {
	return key % Hashmax;
}
//初始化拉链法构造的散列表
void init() {
	for(int i = 0; i < Hashmax; i++) {
		hastab[i] = NULL;
	}
}
//散列表插入运算
void insert_hash(int key) {
	link p; 
	int ok;
	p = (link)malloc(sizeof(node));
	p->key = key;
	p->next = NULL;
	ok = hash_mod(key);	//用取余法求出键值在表中的位置
	p->next = hastab[ok];		//插入到链表表头（不带头节点）
	hastab[ok] = p;
}
int hash_search(int key) {
	link p;
	int ok;
	ok = hash_mod(key);
	p = hastab[ok];
	while(p) {
		if(p->key == key)
			return 1;
		else
			p = p->next;
	}
	return 0;
}
int main() {
	data[0] = 1;
	data[1] = 13;
	data[2] = 20;
	data[3] = 5;
	data[4] = 14;
	data[5] = 33;
	init();
	for(int i = 0; i < MAX; i++)
		insert_hash(data[i]);
	cout<<hash_search(data[2])<<endl;
	return 0;
}
