#include<stdio.h>
#include<iostream>
using namespace std;
#define FINITY 5000
#define M 20
typedef int edgetype;
typedef char vertextype;
typedef int dist[M];
typedef int path[M];
typedef struct{
	vertextype vexs[M];//顶点信息域 
	edgetype  edges[M][M];//邻接矩阵
	int n,e;             //顶点总数，边数 
}Mgraph;

void creat(Mgraph *g){//初始化 
	g->n=4;
	g->e=5;
		g->vexs[0]='0';
		g->vexs[1]='1'; 
		g->vexs[2]='2'; 
		g->vexs[3]='3';
	for(int i=0;i<g->n;i++){
		for(int j=0;j<g->n;j++){
			g->edges[i][j]=FINITY;
			if(i==j)		//若顶点相同，则距离为0 
			g->edges[i][j]=0;
		}
	}
	g->edges[0][1]=1;
	g->edges[0][2]=2;
	g->edges[0][3]=3;
	g->edges[1][2]=4;
	g->edges[2][3]=5;
	g->edges[1][0]=1;
	g->edges[2][0]=2;
	g->edges[3][0]=3;
	g->edges[2][1]=4;
	g->edges[3][2]=5;
}

void dijkstra(Mgraph g,int V0,path p,dist d){
	bool final[M];//判断是否为最短距离 
	int k;
	int v;
	//初始化 
	for(int i = 0;i < g.n;i++){
		final[i] = false;
		d[i] = g.edges[i][V0];
		if(d[i] < FINITY && d[i] > 0){
			p[i] = V0;//先默认前驱都为V0 
		}
		else
		p[i] = -1;
	}
	final[V0] = true; //V0本身就为最短距离 
	d[V0] = 0;
	for(int i = 1;i < g.n;i++){
		int min = FINITY;
		for(k = 0;k < g.n;k++){
			if(d[k] < min&&!final[k]){
				min = d[k];
				v=k;   //记录当前的最短距离 
			}
		}
		if(min == FINITY)
		break;     //结束标志 
		final[v] = true;
		//通过前面已知的最短距离，更新后面的距离 
		for(int j = 0;j < g.n;j++){
			if(!final[j]&&(min+g.edges[v][j] < d[j])){
				p[j] = v;
				d[j] = min+g.edges[v][j];
			}
			
		}
	}
		
}

void print(Mgraph g,path p,dist d){
	int stk[M],pre,top=0;  //用顺序栈来进行输出 
	for(int i=0;i<g.n;i++){
//		cout<<"juli"<<i<<endl;
		stk[top++]=i;
		pre=p[i];
		while(pre!=-1){
			stk[top++]=pre;
			pre=p[pre];
		}
		while(top>=0){
			printf("%2d",stk[top--]);
		}
	}
}
int main(){
	Mgraph g;
	path p;
	dist d;
	creat(&g);
	dijkstra(g,0,p,d);
	print(g,p,d);
	return 0;
} 
