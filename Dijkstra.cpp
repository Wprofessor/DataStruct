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
	vertextype vexs[M];//������Ϣ�� 
	edgetype  edges[M][M];//�ڽӾ���
	int n,e;             //�������������� 
}Mgraph;

void creat(Mgraph *g){//��ʼ�� 
	g->n=4;
	g->e=5;
		g->vexs[0]='0';
		g->vexs[1]='1'; 
		g->vexs[2]='2'; 
		g->vexs[3]='3';
	for(int i=0;i<g->n;i++){
		for(int j=0;j<g->n;j++){
			g->edges[i][j]=FINITY;
			if(i==j)		//��������ͬ�������Ϊ0 
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
	bool final[M];//�ж��Ƿ�Ϊ��̾��� 
	int k;
	int v;
	//��ʼ�� 
	for(int i = 0;i < g.n;i++){
		final[i] = false;
		d[i] = g.edges[i][V0];
		if(d[i] < FINITY && d[i] > 0){
			p[i] = V0;//��Ĭ��ǰ����ΪV0 
		}
		else
		p[i] = -1;
	}
	final[V0] = true; //V0�����Ϊ��̾��� 
	d[V0] = 0;
	for(int i = 1;i < g.n;i++){
		int min = FINITY;
		for(k = 0;k < g.n;k++){
			if(d[k] < min&&!final[k]){
				min = d[k];
				v=k;   //��¼��ǰ����̾��� 
			}
		}
		if(min == FINITY)
		break;     //������־ 
		final[v] = true;
		//ͨ��ǰ����֪����̾��룬���º���ľ��� 
		for(int j = 0;j < g.n;j++){
			if(!final[j]&&(min+g.edges[v][j] < d[j])){
				p[j] = v;
				d[j] = min+g.edges[v][j];
			}
			
		}
	}
		
}

void print(Mgraph g,path p,dist d){
	int stk[M],pre,top=0;  //��˳��ջ��������� 
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
