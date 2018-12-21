#include<bits/stdc++.h>
using namespace std;
#define M 20
typedef char DataType;
typedef struct node {
	int adjvex;
	struct node *next;
} EdgeNode;
typedef struct vnode {
	DataType vertex;
	EdgeNode *FirstEdge;
} VertexNode;
typedef struct {
	VertexNode adjlist[M];
	int n,m;	//�������ͱ��� 
} LinkedGraph;
//��ʼ���ڽӱ� 
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
//������ȱ���
void BFS(LinkedGraph g,int i) {		//������ʼ��i
	EdgeNode *p;
	int queue[M],front,real;
	front = real = 0;
	int tag[M];		//���ʱ������
	memset(tag,0,sizeof(tag));
	queue[real++] = i;
	cout<<g.adjlist[i].vertex;
	tag[i] = 1;
	while(real > front) {
		int ok = queue[front++];
		p = g.adjlist[ok].FirstEdge;
		while(p) {
			if(tag[p->adjvex] == 0) {
				cout<<g.adjlist[p->adjvex].vertex;
				queue[real++] = p->adjvex;
				tag[p->adjvex] = 1;
			}
			p = p->next;
		}
	}
}
int main() {
	LinkedGraph g;
	init(&g);
	BFS(g,0);
	return 0;
}
