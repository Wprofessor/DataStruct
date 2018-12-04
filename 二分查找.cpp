#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define maxsize 1000
using namespace std;
typedef int datatype;
typedef struct {
	datatype data[maxsize];
	int len;
} seqlist;
//非递归二分查找
int binsearch1(seqlist l,datatype key) {
	int low = 0,high = l.len-1,mid;
	while(low <= high) {
		mid = (low + high)/2;
		if(l.data[mid] == key)
			return mid;
		if(l.data[mid] < key) {
			low = mid+1;
		} else {
			high = mid-1;
		}
	}
	return -1;		//检索失败
}
//递归二分查找
int binsearch2(seqlist l,datatype key,int low,int high) {
	int mid;
	if(low > high)	return -1;
	else {
		mid = (low + high)/2;
		if(l.data[mid] == key)	return mid;
		if(l.data[mid] < key)	return binsearch2(l,key,mid+1,high);
		else
		return binsearch2(l,key,low,mid-1);
	}
}
int main() {
	seqlist l;
	for(int i = 0;i <= 54;i++) {
		l.data[i] = i+1;
	}
	l.len = 55;
	cout<<binsearch1(l,34)<<endl;
	cout<<binsearch2(l,50,0,l.len-1)<<endl;
	return 0;
}
