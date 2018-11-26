#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define M 20
#define FINITY 10000
using namespace std;
typedef char vertextype;
typedef int edgetype;
typedef struct {
	vertextype vex[M];
	edgetype edges[M][M];
	int n,e;   //顶点数和边数
} Mgraph;
typedef struct edgedeta {
	int beg,en;
	int length;
} edge;
//初始化图的信息
void init(Mgraph *g) {
	FILE *rt;
	rt = fopen("C:/Users/王教授/Desktop/kruskal.txt","rb");
	if(rt) {
		fscanf(rt,"%d%d",&g->n,&g->e);
		for(int i = 0; i < g->n; i++) {
			fscanf(rt,"%s",&g->vex[i]);       //不能是%c，因为有空格，会形成干扰 
		}
		for(int i = 0; i < g->n; i++) {
			for(int j = 0; j < g->n; j++) {
				if(i == j)
					g->edges[i][j] = 0;
				else
					g->edges[i][j] = FINITY;
			}
		}
		for(int i = 0; i < g->e; i++) {
			int x,y,z;
			fscanf(rt,"%d%d%d",&x,&y,&z);
			g->edges[x][y] = z;
//			cout<<g->edges[x][y]<<endl;
			g->edges[y][x] = z;
		}
		cout<<"emmm"<<endl;
	for(int i = 0; i < g->n; i++)
		for(int j = 0; j < g->n; j++)
		cout<<g->edges[i][j]<<endl;
		cout<<"emmm"<<endl;
		fclose(rt);
	}
	
}
//快速排序
void QuickSort(edge edges[],int left,int right) {
	edge x;
	int i,j;
	if(left < right) {
		i = left;
		j = right;
		x = edges[i];         //第一个元素设为基点
		while(i < j) {
			while(i < j && x.length < edges[j].length)
				j--;
			if(i < j)
				edges[i++].length = edges[j].length;           //这句等价为交换
			while(i < j && x.length > edges[i].length)
				i++;
			if(i < j)
				edges[j--] = edges[i];
		}
		edges[i] = x;
		//递归排序
		QuickSort(edges,left,i-1);
		QuickSort(edges,i+1,right);    //第i个数注意要空出来 
	}
}
//保存所有边的信息
void GetEdge(Mgraph g,edge edges[]) {
	int k = 0;
	for(int i = 0; i < g.n; i++) {
		for(int j = 0; j < i; j++) {			//因为是无向网络，只保存一半就够了
			if(g.edges[i][j] != 0 && g.edges[i][j] < FINITY) {
				edges[k].beg = i;
				edges[k].en = j;
				edges[k++].length = g.edges[i][j];
			}
		}
	}
}
void kruskal(Mgraph g) {
	int k = 0;
	int t;     //中间变量
	int cnvx[M];	//用数组记录顶点的索引
	edge edges[M*M];
	edge tree[M];
	GetEdge(g,edges);
	QuickSort(edges,0,g.e-1);
	for(int i = 0; i < g.n; i++) {
		cnvx[i] = i;
	}
	for(int i = 0; i < g.n-1; i++) {
		while(cnvx[edges[k].beg] == cnvx[edges[k].en])    //判断是否出现回路
			k++;
		tree[i] = edges[k];
		t = edges[k].en;
		//合并连通分量 （并查集的思想）
		for(int i = 0; i < g.n; i++) {
			if(t == cnvx[i])
				cnvx[i] = cnvx[edges[i].beg];
		}
		k++;
	}
	cout<<"最小生成树"<<endl;
	for(int i = 0; i < g.n-1; i++) {
		cout<<g.vex[tree[i].beg]<<"---"<<g.vex[tree[i].en]<<"---"<<tree[i].length<<endl;
	}
}
int main() {
	Mgraph g;
	init(&g);
	kruskal(g);
	return 0;
}
