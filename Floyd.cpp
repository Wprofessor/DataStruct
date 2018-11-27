#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define M 20
#define FINITY 10000
using namespace std;
typedef char vertextype;
typedef int edgetype;
typedef int dist[M][M];  	//����
typedef int path[M][M]; 	//·��
typedef struct {
	vertextype vex[M];
	edgetype edges[M][M];
	int n,e;   //�������ͱ���
} Mgraph;
//��ʼ��ͼ����Ϣ
void init(Mgraph *g) {
	FILE *rt;
	rt = fopen("C:/Users/������/Desktop/Floyd.txt","rb");
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
		fclose(rt);
	}
}
void  Floyd(Mgraph g,path p,dist d) {
	//��ʼ��
	for(int i = 0; i < g.n; i++) {
		for(int j = 0; j < g.n; j++) {
			d[i][j] = g.edges[i][j];
			if(i != j && d[i][i < FINITY]) {
				p[i][j] = i;
			} else {
				p[i][j] = -1;
			}
		}
	}
	//�������ÿ�Զ�������̾���
	//����ÿ�ֿ��ܵ����
	for(int k = 0; k < g.n; k++)
		for(int i = 0; i < g.n; i++) {
			for(int j = 0; j < g.n; j++) {
				if(d[i][j] > (d[i][k] + d[k][j])) {		//��������ʽ����
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = k;	//�޸�ǰ������
				}
			}
		}
}
int main() {
	Mgraph g;
	path p;
	dist d;
	init(&g);
	Floyd(g,p,d);
	cout<<"������Ҫ��ѯ�Ķ�����"<<endl;
	int x,y;
	cin>>x>>y;
	for(int i = 0; i < g.n; i++) {
		for(int j = 0; j < g.n; j++) {
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i = 0; i < g.n; i++) {
		for(int j = 0; j < g.n; j++) {
			cout<<p[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<x<<"--->";
	while(p[x][y] != -1 && p[x][y] != x){
		cout<<p[x][y]<<"--->";
		x = p[x][y];
	}
	cout<<y<<endl;
	return 0;
}
