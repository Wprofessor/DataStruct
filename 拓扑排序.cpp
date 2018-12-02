#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define M 20
using namespace std;
typedef char vertextype;
typedef struct node {	//�߽������ 
	int adjvex;
	struct node *next;
}edgenode;
typedef struct {
	edgenode* FirstEdge;
	vertextype vertex;
	int id;       //����� 
}vertexnode;
typedef struct {
	vertexnode adjlist[M];
	int n,e;
}AovGraph;
//�����ڽӱ� 
void init(AovGraph *g) {
	edgenode *q;
	int x,y;
	//���붥�����ͱ���
	cin>>x>>y;
	g->n = x;
	g->e = y;
	char data;
	int id;
	for(int i = 0; i < g->n; i++) {
		cout<<"������ڵ���Ϣ"<<endl;
		cin>>data;
		g->adjlist[i].vertex = data;
		cout<<"�������������Ϣ"<<endl;
		cin>>id;
		g->adjlist[i].id = id; 
		g->adjlist[i].FirstEdge = NULL;
	}
	for(int i = 0; i < g->e; i++) {
		cout<<"����ߵĶ������"<<endl;
		cin>>x>>y;
		q = (edgenode *)malloc(sizeof(edgenode));
		q->adjvex = y;
		q->next = g->adjlist[x].FirstEdge; //���½ڵ���뵽ͷ��
		g->adjlist[x].FirstEdge = q;
	}

}
int TopSort(AovGraph g) {
	int k = 0,v,flag[M],j;	//flag�ж��Ƿ��Ѿ���������� 
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
	while(front < rear) {	//���в�Ϊ��ʱ 
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
