#include<stdio.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
int pre[MAXSIZE];
int find( int x ) {     //寻根
	int val = x;
	while( val != pre[val] ) {
		val = pre[val];
	}
	int j = x;
	int ok;
	while( j != val ) {    //路径压缩
		ok = pre[j];
		pre[ok] = val;
	}
	return val;
}
void join(int x, int y) {    //合并 
	int fx = find(x),fy = find(y);
	if(fx != fy){      //如果两个的祖先不一样 
		pre[fx] = fy;         //让fy当fx的祖先 
	}
}
int main() {
	cout<<"成功"<<endl;
	return 0;
}
