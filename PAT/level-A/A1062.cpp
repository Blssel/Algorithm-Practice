// A1062.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef struct{
	char id[10];
	int v;
	int t;
	int total;
}person;
person input[100100],sage[100100],noble[100100],fool[100100],small[100100];
bool cmp(person a,person b){
	if(a.total !=b.total ) return a.total >b.total ;
	else if(a.v!=b.v) return a.v>b.v;
	else return strcmp(a.id ,b.id)<0;
}
int main()
{
	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	for(int i=0;i<n;i++){
		scanf("%s %d%d",input[i].id,&input[i].v,&input[i].t);
		input[i].total=input[i].v+input[i].t; 
	}
	int ss=0,nn=0,ff=0,sm=0,m=n;
	for(int i=0;i<n;i++){
		if(input[i].v<l||input[i].t<l){
			m--;
		}else if(input[i].v >=h&&input[i].t >=h){
			sage[ss++]=input[i];
		}else if(input[i].t <h&&input[i].v >=h){
			noble[nn++]=input[i];
		}else if(input[i].t<h&&input[i].v <h&&input[i].v >=input[i].t){
			fool[ff++]=input[i];
		}else{
			small[sm++]=input[i];
		}
	}
	sort(sage,sage+ss,cmp);
	sort(noble,noble+nn,cmp);
	sort(fool,fool+ff,cmp);
	sort(small,small+sm,cmp);
	printf("%d\n",m);
	for(int i=0;i<ss;i++)
		printf("%s %d %d\n",sage[i].id,sage[i].v,sage[i].t);
	for(int i=0;i<nn;i++)
		printf("%s %d %d\n",noble[i].id,noble[i].v,noble[i].t);
	for(int i=0;i<ff;i++)
		printf("%s %d %d\n",fool[i].id,fool[i].v,fool[i].t);
	for(int i=0;i<sm;i++)
		printf("%s %d %d\n",small[i].id,small[i].v,small[i].t);
	return 0;
}

