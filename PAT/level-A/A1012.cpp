// A1012.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
struct{
	int id;
	int a,c,m,e;
	int rank[4];
}student[2010];
char subj[4]={'A','C','M','E'};
int id[2010];
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",student[i].id,student[i].c,student[i].m,student[i].e);
		student[i].a=(student[i].c+student[i].m+student[i].e)/3;
	}
	for(int i=0;i<M;i++){
		scanf("%d",id[i]);
	}

	return 0;
}

