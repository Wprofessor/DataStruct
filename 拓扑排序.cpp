#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define M 20
using namespace std;
typedef char vertextype;
typedef struct node {	//边结点类型 
	int adjvex;
	struct node *next;
}edgenode;
typedef struct {
	edgenode* FirstEdge;
	vertextype vertex;
	int id;       //入度域 
}vertexnode;
typedef struct {
	vertexnode adjlist[M];
	int n,e;
}AovGraph;
//创建邻接表 
void init(AovGraph *g) {
	edgenode *q;
	int x,y;
	//输入顶点数和边数
	cin>>x>>y;
	g->n = x;
	g->e = y;
	char data;
	int id;
	for(int i = 0; i < g->n; i++) {
		cout<<"请输入节点信息"<<endl;
		cin>>data;
		g->adjlist[i].vertex = data;
		cout<<"请输入入度域信息"<<endl;
		cin>>id;
		g->adjlist[i].id = id; 
		g->adjlist[i].FirstEdge = NULL;
	}
	for(int i = 0; i < g->e; i++) {
		cout<<"输入边的顶点序号"<<endl;
		cin>>x>>y;
		q = (edgenode *)malloc(sizeof(edgenode));
		q->adjvex = y;
		q->next = g->adjlist[x].FirstEdge; //将新节点插入到头部
		g->adjlist[x].FirstEdge = q;
	}

}
int TopSort(AovGraph g) {
	int k = 0,v,flag[M],j;	//flag判断是否已经进入过队列 
	int queue[M];
	int front,rear;
	edgenode* p;
	front = rear = 0;
	for(int i = 0;i < g.n;i++)  flag[i] = 0;
	for(int i = 0;i < g.n;i++) {
		if(g.adjlist[i].id == 0 && flag[i] == 0) {
			queue[rear++] = i;
			flag[i] = 1;
		}
	}
	while(front < rear) {	//队列不为空时 
		v = queue[front++];
		cout<<g.adjlist[v].vertex;
		k++;
		p = g.adjlist[v].FirstEdge;
		while(p) {
			j = p->adjvex;
			if(--g.adjlist[j].id == 0 && flag[j] == 0){
				queue[rear++] = j;
				flag[j] = 1;
			}
			p = p->next;
		}
	}
	return k; 
}
int main() {
	AovGraph g;
	init(&g);
	cout<<TopSort(g)<<endl;
	return 0;
}
