#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define M 20
using namespace std;
int visit[M+5];

typedef char Datatype;
//邻接边的信息
typedef struct node {
	int adjvex;      //与之邻接的点的索引
	struct node *next;
} EdgeNode;
//节点的信息
typedef struct vnode {
	Datatype vertex;
	EdgeNode *FirstEdge;    //第一个邻接边
} VertexNode;
typedef struct {
	VertexNode adjlist[M];
	int n,m;    //顶点数和边数
} LinkedGraph;
void init(LinkedGraph *g) {
	EdgeNode *q;
	int x,y;
	//输入顶点数和边数
	cin>>x>>y;
	g->n = x;
	g->m = y;
	char data;
	for(int i = 0; i < g->n; i++) {
		cout<<"请输入节点信息"<<endl;
		cin>>data;
		g->adjlist[i].vertex = data;
		g->adjlist[i].FirstEdge = NULL;
	}
	for(int i = 0; i < g->m; i++) {
		cout<<"输入边的顶点序号"<<endl;
		cin>>x>>y;
		q = (EdgeNode *)malloc(sizeof(EdgeNode));
		q->adjvex = y;
		q->next = g->adjlist[x].FirstEdge; //将新节点插入到头部
		g->adjlist[x].FirstEdge = q;

		q = (EdgeNode *)malloc(sizeof(EdgeNode));
		q->adjvex = x;
		q->next = g->adjlist[y].FirstEdge; //将新节点插入到头部
		g->adjlist[y].FirstEdge = q;
	}

}
void DFS(LinkedGraph g,int i) {
	EdgeNode *p;
	visit[i] = 1;
	p = g.adjlist[i].FirstEdge;
	while(p) {
		if(!visit[p->adjvex])
			DFS(g,p->adjvex);
		p = p->next;
	}
}
//用于遍历非连通图
void FINDFS(LinkedGraph g) {
	//初始化标记数组
	memset(visit,0,sizeof(visit));
	for(int i = 0; i < g.n; i++) {
		if(!visit[i])
			DFS(g,i);
	}
}
int main() {
	LinkedGraph g;
	init(&g);
	FINDFS(g);
	for(int i = 0; i < g.n; i++) {
		if(visit[i]) {
			cout<<g.adjlist[i].vertex<<endl;
		}
	}
	return 0;
}
