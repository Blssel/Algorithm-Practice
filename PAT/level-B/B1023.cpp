// B1023.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
int hash[10];
int main()
{
	for(int i=0;i<10;i++){
		int tmp;
		scanf("%d",&tmp);
		hash[i]=tmp;
	}
	for(int i=1;i<10;i++){
		if(hash[i]>0){
			printf("%d",i);
			hash[i]--;
			break;
		}
	}
	for(int i=0;i<10;i++){
		while(hash[i]>0){
			printf("%d",i);
			hash[i]--;
		}
	}
	return 0;
}

