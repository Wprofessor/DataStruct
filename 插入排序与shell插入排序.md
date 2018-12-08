# 插入排序
## 基本思想：
### 从第二个元素开始，依次选择哨兵元素，然后依次将哨兵元素和前面的元素进行比较，如果前一个元素大于该哨兵元素（从小到大排序），则把前面那个元素移动到后一个位置；继续往前比较，直到找某个元素不大于该哨兵元素，则把哨兵元素插入到位置上；
## 基本步骤：
* ### 第二个元素开始外后选择一个哨兵元素；
* ### 让哨兵元素和前面的元素进行比较，找到合适的位置插入；
* ### 循环上面两步，直到选择完所有元素；
## *代码*：
```
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
typedef int keytype;
typedef struct {
	keytype key;
	int other;
} recordtype;
typedef struct {
	recordtype r[MAXSIZE + 1];		//r[0]存放哨兵 
	int length;
} table;
//插入排序
void insertsort(table *tab) {
	int ok;
	for(int i = 2;i <= tab->length;i++) {
		ok = i-1;
		tab->r[0] = tab->r[i];		//设置哨兵
		while(tab->r[0].key < tab->r[ok].key) {
			tab->r[ok+1] = tab->r[ok];
			ok--;
		}
		tab->r[ok+1] = tab->r[0];	//将哨兵插入 
	}
} 
int main() {
	table tab;
	tab.r[1].key = 3;
	tab.r[2].key = 4;
	tab.r[3].key = 2;
	tab.r[4].key = 76;
	tab.r[5].key = 20;
	tab.r[6].key = 1;
	tab.r[7].key = 39;
	tab.length = 7;
	insertsort(&tab);
	for(int i = 1;i <= tab.length;i++) {
		cout<<"--"<<tab.r[i].key<<endl;
	} 
	return 0;
}

```

# shell插入排序
## 基本思想：
### shell排序是相当于把一个数组中的所有元素分成几部分来排序；先把几个小部分的元素排序好，让元素大概有个顺序，最后再全面使用插入排序。一般最后一次排序都是和上面的插入排序一样的，每部分的排序也基本和插入排序类似；
## 基本步骤：
### 比如：数组有10个元素，增量 d = 5；则比较元素为：array[0]    array[0+d]    array[0+2d]  array[0+3d]；（当然 d 会改变的，d = d/2  或者 d = d -2）
### 第一次  d = 5  比较的元素为：array[0]  , array[5]  
### 第二次  d = d/2 = 2 比较元素为：array[0]  , array[2]  , array[4] , array[6] , array[8]
### 第三次  d = d/2 = 1 比较元素为：从array[0] 到  array[9]

## *代码*：
```
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define MAXSIZE 100
using namespace std;
typedef int keytype;
typedef struct {
	keytype key;
	int other;
} recordtype;
typedef struct {
	recordtype r[MAXSIZE + 1];		//r[0]不存放排序码 
	int length;
} table;
//shell插入排序
void shellinsertsort(table *tab) {
	int d,ok;
	d = tab->length/2;
	while(d >= 1) {
		for(int i = d+1;i <= tab->length;i++) {
			tab->r[0] = tab->r[i];	//设置哨兵 
			ok = i-d;	//向前找插入位置 
			while(ok > 0 && tab->r[0].key < tab->r[ok].key) {
                             //类似于插入排序，记录后移
				tab->r[ok+d] = tab->r[ok];					
				ok -= d; 
			}
			tab->r[ok+d] = tab->r[0];
		}
		d /= 2;
	}
}
int main() {
	table tab;
	tab.r[1].key = 3;
	tab.r[2].key = 4;
	tab.r[3].key = 2;
	tab.r[4].key = 76;
	tab.r[5].key = 20;
	tab.r[6].key = 1;
	tab.r[7].key = 39;
	tab.length = 7;
	shellinsertsort(&tab);
	for(int i = 1;i <= tab.length;i++) {
		cout<<"--"<<tab.r[i].key<<endl;
	} 
	return 0;
}
```

## 对比后发现，shell插入排序就是在插入排序的基础上进行的改变