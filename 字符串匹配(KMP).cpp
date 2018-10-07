	#include<stdio.h>
	#include<string.h>
	#include<iostream>
	using namespace std;
	#define M 20
	//��ʼ��next���� 
	void get_next(char *t,int *next){
		int i = 0,j = -1;
		next[0] = -1;                      //next�����һ��ֵ��Զ��-1 
		while(i < strlen(t)){              //�ٽ����� 
			if(j == -1 || t[i] == t[j]){	
				i++;
				j++;
				next[i] = next[j] + 1;			
			}
			else{			
				j = next[j];			   //��ǰ�ݹ���nextֵ 
			}
		}
	}
	
	int KMP(char *s,char *t,int pos,int *next){
		int i = pos;                       //�������Ҫ���Զ��忪ʼλ�� 
		int j = 0;
		int len1 = strlen(s),len2 = strlen(t);
		while(i < len1 && j < len2 ){
			if(s[i] == t[j] || j == -1){
				i++;
				j++;
			}
			else{
				j = next[j];               //�ƶ��ľ����������Ӧ��nextֵ 
			}
		}
		if(j >= len2){
			return 1;                      //ƥ��ɹ�����1 
		}
		else{
			return 0;					   //ƥ��ʧ�ܷ���0 
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
