#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
typedef char datatype;
typedef struct node {
	datatype info;
	struct node *lchild,*rchild;
} node,*treenode;
treenode creatTree() {
	char ch;
	treenode t;
	ch = getchar();
	if(ch == '#')                            //空子树用#号代替
		t = NULL;
	else {
		t = (node *)malloc(sizeof(node));
		t->info = ch;
		t->lchild = creatTree();            //前序遍历递归建树
		t->rchild = creatTree();
	}
	return t;                               //返回根节点
}
void perorder1(treenode t) {				//前序遍历的非递归实现
	treenode data[MAXSIZE];
	int top = 0;
	while(t || top != 0) {
		if(t) {
			cout<<t->info;
			data[top] = t;
			top++;
			t = t->lchild;
		} else {
			top--;
			t = data[top];
			t = t->rchild;
		}
	}
	cout<<endl;
}
void inorder1(treenode t) {					//中序遍历的非递归实现
	treenode data[MAXSIZE];
	int top = 0;
	while(t || top != 0) {
		if(t) {
			data[top] = t;
			top++;
			t = t->lchild;
		} else {
			top--;
			t = data[top];
			cout<<t->info;
			t = t->rchild;
		}
	}
	cout<<endl;
}
void postorder1(treenode t) {				//后序遍历的非递归实现
	treenode data[MAXSIZE];
	int sign[MAXSIZE];                      //标记数组
//	memset(sign,-1,sizeof(sign));			//将标记数组初始化为-1
	int top = 0;
	while(t || top != 0) {
		if(t) {
			data[top] = t;
			sign[top] = 0;
			top++;
			t = t->lchild;
		} else if(sign[top-1] == 1) {
			top--;
			t = data[top];
			cout<<t->info;
			t = NULL;                       //访问后要置空，防止死循环 
		} else if(sign[top-1] == 0) {
			t = data[top-1];
			sign[top-1] = 1;
			t = t->rchild;
		} else {
			t == NULL;
		}
	}
	cout<<endl;
}
int main() {
	treenode t;
	t = creatTree();
	perorder1(t);
	inorder1(t);
	postorder1(t);
	return 0;
}

