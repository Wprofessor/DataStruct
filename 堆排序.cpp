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
//筛选算法：保证满足堆排序结构，每个节点都大于或小于子节点 
//k为调整位置，m为堆的大小 
void sift(table *tab ,int k,int m) {
	int i,j,finished;
	i = k;
	j = 2*i;
	tab->r[0] = tab->r[k];		//将要调整位置的元素保存在0位置 
	finished = 0;
	//若这个节点不满足堆结构，一直循环直至当前节点的所有子节点都满足 
	while((j <= m) && (!finished)) {
		//下面两个if目的是找的子节点中最小的 
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
//堆排序算法 
void heapsort(table *tab) {
	//对所有元素建堆 
	for(int i = tab->length/2;i >= 1;i--)
	sift(tab,i,tab->length);
	for(int i = tab->length;i >= 2;i--) {
		//第一个元素和最后一个交换位置 
		tab->r[0] = tab->r[i];
		tab->r[i] = tab->r[1];
		tab->r[1] = tab->r[0];
		//对除最后一个元素以外的所有元素又重新建堆 
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
	//由于建堆时小的为父节点，排序是小的和最后一个元素交换
	//因此，此时为降序排序 
	heapsort(&tab);
	for(int i = 1;i <= tab.length;i++) {
		cout<<"---"<<tab.r[i].key<<endl;
	}
	return 0;
} 
