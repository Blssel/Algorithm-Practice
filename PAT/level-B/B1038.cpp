// B1038.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
int fen[110];
int main()
{
	for(int i=0;i<110;i++){
		fen[i]=0;
	}
	int n;
	int tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		fen[tmp]++;
	}
	int k,cha[100010];
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&cha[i]);
	}
	for(int i=0;i<k;i++){
		printf("%d",fen[cha[i]]);
		if(i!=k-1)
			printf(" ");
	}
	return 0;
}

