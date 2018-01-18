// A1041.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
int hash[10010];

int main()
{
	memset(hash,0,sizeof(hash));
	hash[0]=11000;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d",&tmp);
		if(hash[tmp]==0){
			hash[tmp]=i;
		}else if(hash[tmp]>0){
			hash[tmp]=-1;
		}else
			continue;
	}
	int unique=0;
	for(int i=1;i<10010;i++){
		if(hash[i]>0&&hash[i]<hash[unique]){
			unique=i;
		}
	}
	if(unique==0)
		printf("None\n");
	else
		printf("%d\n",unique);
	return 0;
}
