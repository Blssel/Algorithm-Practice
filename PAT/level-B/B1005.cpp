// B1005.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
int hash[101];

int main()
{
	memset(hash,-1,sizeof(hash));//1就是指被覆盖
	int k;
	scanf("%d",&k);
	int kk=k;
	while(kk--){
		int n;
		scanf("%d",&n);
		if(hash[n]!=1)
			hash[n]=0;
		while(n!=1){
			if(n%2==0){
				n/=2;
				if(n<=100)
					hash[n]=1;
			}else{
				n=(3*n+1)/2;
				if(n<=100)
					hash[n]=1;
			}
		}
	}
	//
	int first;
	for(int i=100;i>=2;i--){
		if(hash[i]==0){
			first=i;
			break;
		}
	}
	printf("%d",first);
	for(int i=first-1;i>=2;i--){
		if(hash[i]==0){
			printf(" %d",i);
		}
	}
	
	return 0;
}

