#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define M 20
using namespace std;
int visit[M+5];

typedef char Datatype;
//�ڽӱߵ���Ϣ
typedef struct node {
	int adjvex;      //��֮�ڽӵĵ������
	struct node *next;
} EdgeNode;
//�ڵ����Ϣ
typedef struct vnode {
	Datatype vertex;
	EdgeNode *FirstEdge;    //��һ���ڽӱ�
} VertexNode;
typedef struct {
	VertexNode adjlist[M];
	int n,m;    //�������ͱ���
} LinkedGraph;
void init(LinkedGraph *g) {
	EdgeNode *q;
	int x,y;
	//���붥�����ͱ���
	cin>>x>>y;
	g->n = x;
	g->m = y;
	char data;
	for(int i = 0; i < g->n; i++) {
		cout<<"������ڵ���Ϣ"<<endl;
		cin>>data;
		g->adjlist[i].vertex = data;
		g->adjlist[i].FirstEdge = NULL;
	}
	for(int i = 0; i < g->m; i++) {
		cout<<"����ߵĶ������"<<endl;
		cin>>x>>y;
		q = (EdgeNode *)malloc(sizeof(EdgeNode));
		q->adjvex = y;
		q->next = g->adjlist[x].FirstEdge; //���½ڵ���뵽ͷ��
		g->adjlist[x].FirstEdge = q;

		q = (EdgeNode *)malloc(sizeof(EdgeNode));
		q->adjvex = x;
		q->next = g->adjlist[y].FirstEdge; //���½ڵ���뵽ͷ��
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
//���ڱ�������ͨͼ
void FINDFS(LinkedGraph g) {
	//��ʼ���������
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
