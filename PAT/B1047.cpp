// B1047.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
int hash[1010];
int main()
{
	memset(hash,0,sizeof(hash));
	int n;
	scanf("%d",&n);
	int team,member,score;
	for(int i=1;i<=n;i++){
		scanf("%d-%d %d",&team,&member,&score);
		hash[team]+=score;
	}
	int max_team=0;
	for(int i=1;i<=1010;i++){
		if(hash[i]>hash[max_team])
			max_team=i;
	}
	printf("%d %d",max_team,hash[max_team]);
	return 0;
}

