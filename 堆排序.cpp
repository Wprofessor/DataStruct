#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
typedef int keytype;
typedef struct {
	keytype key;
	int other;
} recordtype;
typedef struct {
	recordtype r[MAXSIZE + 1];
	int length;
} table;
//ɸѡ�㷨����֤���������ṹ��ÿ���ڵ㶼���ڻ�С���ӽڵ� 
//kΪ����λ�ã�mΪ�ѵĴ�С 
void sift(table *tab ,int k,int m) {
	int i,j,finished;
	i = k;
	j = 2*i;
	tab->r[0] = tab->r[k];		//��Ҫ����λ�õ�Ԫ�ر�����0λ�� 
	finished = 0;
	//������ڵ㲻����ѽṹ��һֱѭ��ֱ����ǰ�ڵ�������ӽڵ㶼���� 
	while((j <= m) && (!finished)) {
		//��������ifĿ�����ҵ��ӽڵ�����С�� 
		if((j < m) && (tab->r[j+1].key < tab->r[j].key))
		j++;
		if(tab->r[0].key <= tab->r[j].key)
		finished = 1;
		else {
			tab->r[i] = tab->r[j];
			i = j;
			j = 2*j; 
		}
	}
	tab->r[i] = tab->r[0];
}
//�������㷨 
void heapsort(table *tab) {
	//������Ԫ�ؽ��� 
	for(int i = tab->length/2;i >= 1;i--)
	sift(tab,i,tab->length);
	for(int i = tab->length;i >= 2;i--) {
		//��һ��Ԫ�غ����һ������λ�� 
		tab->r[0] = tab->r[i];
		tab->r[i] = tab->r[1];
		tab->r[1] = tab->r[0];
		//�Գ����һ��Ԫ�����������Ԫ�������½��� 
		sift(tab,1,i-1);
	} 
}
int main() {
	table tab;
	tab.r[1].key = 3;
	tab.r[2].key = 4;
	tab.r[3].key = 2;
	tab.r[4].key = 76;
	tab.r[5].key = 20;
	tab.r[6].key = 1;
	tab.r[7].key = 39;
	tab.length = 7;
	//���ڽ���ʱС��Ϊ���ڵ㣬������С�ĺ����һ��Ԫ�ؽ���
	//��ˣ���ʱΪ�������� 
	heapsort(&tab);
	for(int i = 1;i <= tab.length;i++) {
		cout<<"---"<<tab.r[i].key<<endl;
	}
	return 0;
} 
