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
	int n,e;   //�������ͱ���
} Mgraph;
typedef struct edgedeta {
	int beg,en;
	int length;
} edge;
//��ʼ��ͼ����Ϣ
void init(Mgraph *g) {
	FILE *rt;
	rt = fopen("C:/Users/������/Desktop/kruskal.txt","rb");
	if(rt) {
		fscanf(rt,"%d%d",&g->n,&g->e);
		for(int i = 0; i < g->n; i++) {
			fscanf(rt,"%s",&g->vex[i]);       //������%c����Ϊ�пո񣬻��γɸ��� 
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
//��������
void QuickSort(edge edges[],int left,int right) {
	edge x;
	int i,j;
	if(left < right) {
		i = left;
		j = right;
		x = edges[i];         //��һ��Ԫ����Ϊ����
		while(i < j) {
			while(i < j && x.length < edges[j].length)
				j--;
			if(i < j)
				edges[i++].length = edges[j].length;           //���ȼ�Ϊ����
			while(i < j && x.length > edges[i].length)
				i++;
			if(i < j)
				edges[j--] = edges[i];
		}
		edges[i] = x;
		//�ݹ�����
		QuickSort(edges,left,i-1);
		QuickSort(edges,i+1,right);    //��i����ע��Ҫ�ճ��� 
	}
}
//�������бߵ���Ϣ
void GetEdge(Mgraph g,edge edges[]) {
	int k = 0;
	for(int i = 0; i < g.n; i++) {
		for(int j = 0; j < i; j++) {			//��Ϊ���������磬ֻ����һ��͹���
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
	int t;     //�м����
	int cnvx[M];	//�������¼���������
	edge edges[M*M];
	edge tree[M];
	GetEdge(g,edges);
	QuickSort(edges,0,g.e-1);
	for(int i = 0; i < g.n; i++) {
		cnvx[i] = i;
	}
	for(int i = 0; i < g.n-1; i++) {
		while(cnvx[edges[k].beg] == cnvx[edges[k].en])    //�ж��Ƿ���ֻ�·
			k++;
		tree[i] = edges[k];
		t = edges[k].en;
		//�ϲ���ͨ���� �����鼯��˼�룩
		for(int i = 0; i < g.n; i++) {
			if(t == cnvx[i])
				cnvx[i] = cnvx[edges[i].beg];
		}
		k++;
	}
	cout<<"��С������"<<endl;
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
