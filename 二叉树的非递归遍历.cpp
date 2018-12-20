#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
typedef char datatype;
typedef struct node {
	datatype info;
	struct node *lchild,*rchild;
} node,*treenode;
treenode creatTree() {
	char ch;
	treenode t;
	cin>>ch;
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
//前序非递归遍历
void perorder(treenode t) {
	treenode data[MAXSIZE]; //创建栈结构
	int top = 0;
	while(t || top != 0) {
		if(t) {
			cout<<t->info;
			data[top++] = t;
			t = t->lchild;
		} else {
			top--;
			t = data[top];
			t = t->rchild;
		}
	}
	cout<<endl;
}
//中序非递归遍历
void inorder(treenode t) {
	treenode data[MAXSIZE];
	int top = 0;
	while(t || top != 0) {
		if(t) {
			data[top++] = t;
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
//后序非递归遍历
void postorder(treenode t) {
	treenode data[MAXSIZE];
	int top = 0;
	int tag[MAXSIZE]; 	//标记数组
	memset(tag,0,sizeof(tag));
	while(t || top != 0) {
		if(t) {
			data[top++] = t;
			t = t->lchild;
		} else {
			if(tag[top-1] == 1) {
				top--;
				t = data[top];
				cout<<t->info;
				tag[top] = 0;
				t = NULL;
			} else {
				tag[top-1] = 1;
				t = data[top-1];
				t = t->rchild;
			}
		}
	}
	cout<<endl; 
}
int main() {
	treenode t;
	t = creatTree();
	perorder(t);
	inorder(t);
	postorder(t);
	return 0;
}
