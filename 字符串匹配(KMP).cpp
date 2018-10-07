	#include<stdio.h>
	#include<string.h>
	#include<iostream>
	using namespace std;
	#define M 20
	//初始化next数组 
	void get_next(char *t,int *next){
		int i = 0,j = -1;
		next[0] = -1;                      //next数组第一个值永远是-1 
		while(i < strlen(t)){              //临界条件 
			if(j == -1 || t[i] == t[j]){	
				i++;
				j++;
				next[i] = next[j] + 1;			
			}
			else{			
				j = next[j];			   //往前递归找next值 
			}
		}
	}
	
	int KMP(char *s,char *t,int pos,int *next){
		int i = pos;                       //根据你的要求自定义开始位置 
		int j = 0;
		int len1 = strlen(s),len2 = strlen(t);
		while(i < len1 && j < len2 ){
			if(s[i] == t[j] || j == -1){
				i++;
				j++;
			}
			else{
				j = next[j];               //移动的距离就是所对应的next值 
			}
		}
		if(j >= len2){
			return 1;                      //匹配成功返回1 
		}
		else{
			return 0;					   //匹配失败返回0 
		}
	}
	int main(){
		int next[M];
		char s[3*M];
		char t[M];
		cin>>s;
		cin>>t;
		get_next(t,next);
		int ok = KMP(s,t,0,next);
		cout<<ok<<endl;
		return 0;
	}
