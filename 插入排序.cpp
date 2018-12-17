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
	recordtype r[MAXSIZE + 1];		//r[0]´æ·ÅÉÚ±ø
	int length;
} table;
//²åÈëÅÅĞò
void insertsort(table *tab) {
	int ok;
	for(int i = 2; i <= tab->length; i++) {
		ok = i-1;
		tab->r[0] = tab->r[i];		//ÉèÖÃÉÚ±ø
		while(tab->r[0].key < tab->r[ok].key) {
			tab->r[ok+1] = tab->r[ok];
			ok--;
		}
		tab->r[ok+1] = tab->r[0];	//½«ÉÚ±ø²åÈë
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
	insertsort(&tab);
	for(int i = 1; i <= tab.length; i++) {
		cout<<"--"<<tab.r[i].key<<endl;
	}
	return 0;
}

