#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define maxsize 1000
using namespace std;
typedef int datatype;
typedef struct {
	datatype data[maxsize];
	int length;
} seqlist;
//������ṹ 
typedef struct {
	datatype key;	//�ؼ��� 
	int address;	//��ַ 
} indexnode;
int IndexSearch(seqlist l,indexnode index[],int len ,datatype key) {	//len��ʾ�ֿ�������keyΪҪ�ҵĹؼ��� 
	int ok = 0,val;
	while(ok < len && key > index[ok].key)  ok++;
	if(ok >= len)	//���key�ȱ�������Ԫ��ֵ��Ҫ�������ʧ�� 
	return -1;
	else {
		if(ok == len-1) {	//��������һ���е�Ԫ�� 
			val = index[len].address;
			for(int i = val;i < l.length;i++) {
				if(l.data[i] == key)
				return i;
			}
			return -1;
		} else {
			for(int i = index[ok].address;i < index[ok+1].address;i++) {
				if(l.data[i] == key)
				return i;
			}
			return -1;
		}
	}
}
int main() {
	seqlist l;
	l.data[0] = 20;
	l.data[1] = 4;
	l.data[2] = 25;
	l.data[3] = 17;
	l.data[4] = 3;
	l.data[5] = 12;
	l.data[6] = 6;
	l.data[7] = 40;
	l.data[8] = 30;
	l.data[9] = 27;
	l.data[10] = 55;
	l.data[11] = 48;
	l.data[12] = 35;
	l.data[13] = 70;
	l.data[14] = 66;
	l.data[15] = 90;
	l.data[16] = 60;
	l.data[17] = 86;
	l.data[18] = 73;
	l.data[19] = 69;
	indexnode index[3];
	index[0].key = 25;
	index[0].address = 0;
	index[1].key = 55;
	index[1].address = 7;
	index[2].key = 90;
	index[2].address = 13;
	cout<<IndexSearch(l,index,3,48)<<endl;
	return 0;
}
