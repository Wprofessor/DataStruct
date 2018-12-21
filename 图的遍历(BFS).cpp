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
	int n,m;	//顶点数和边数 
} LinkedGraph;
//初始化邻接表 
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
//广度优先遍历
void BFS(LinkedGraph g,int i) {		//遍历起始点i
	EdgeNode *p;
	int queue[M],front,real;
	front = real = 0;
	int tag[M];		//访问标记数组
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
