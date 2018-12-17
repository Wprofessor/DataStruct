#include<bits/stdc++.h>
using namespace std;
//�ؼ��ּ��ϳ���
#define MAX 6
//hash��
#define Hashmax 5
int data[MAX];
typedef struct list {
	int key;	//��ֵ
	struct list *next;
} node , *link;
//����������ɢ�б�
link hastab[Hashmax];
//���෨ɢ�к���
int hash_mod(int key) {
	return key % Hashmax;
}
//��ʼ�������������ɢ�б�
void init() {
	for(int i = 0; i < Hashmax; i++) {
		hastab[i] = NULL;
	}
}
//ɢ�б��������
void insert_hash(int key) {
	link p; 
	int ok;
	p = (link)malloc(sizeof(node));
	p->key = key;
	p->next = NULL;
	ok = hash_mod(key);	//��ȡ�෨�����ֵ�ڱ��е�λ��
	p->next = hastab[ok];		//���뵽�����ͷ������ͷ�ڵ㣩
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
