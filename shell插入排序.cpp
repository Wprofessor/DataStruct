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
	recordtype r[MAXSIZE + 1];		//r[0]²»´æ·ÅÅÅĞòÂë
	int length;
} table;
//shell²åÈëÅÅĞò
void shellinsertsort(table *tab) {
	int d,ok;
	d = tab->length/2;
	while(d >= 1) {
		for(int i = d+1; i <= tab->length; i++) {
			tab->r[0] = tab->r[i];		//ÉèÖÃÉÚ±ø
			ok = i-d;					//ÏòÇ°ÕÒ²åÈëÎ»ÖÃ
			while(ok > 0 && tab->r[0].key < tab->r[ok].key) {
				tab->r[ok+d] = tab->r[ok];				//ÀàËÆÓÚ²åÈëÅÅĞò£¬¼ÇÂ¼ºóÒÆ
				ok -= d;
			}
			tab->r[ok+d] = tab->r[0];
		}
		d /= 2;
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
	shellinsertsort(&tab);
	for(int i = 1; i <= tab.length; i++) {
		cout<<"--"<<tab.r[i].key<<endl;
	}
	return 0;
}
