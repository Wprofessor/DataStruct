#include<stdio.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
int pre[MAXSIZE];
int find( int x ) {     //Ѱ��
	int val = x;
	while( val != pre[val] ) {
		val = pre[val];
	}
	int j = x;
	int ok;
	while( j != val ) {    //·��ѹ��
		ok = pre[j];
		pre[ok] = val;
	}
	return val;
}
void join(int x, int y) {    //�ϲ� 
	int fx = find(x),fy = find(y);
	if(fx != fy){      //������������Ȳ�һ�� 
		pre[fx] = fy;         //��fy��fx������ 
	}
}
int main() {
	cout<<"�ɹ�"<<endl;
	return 0;
}
