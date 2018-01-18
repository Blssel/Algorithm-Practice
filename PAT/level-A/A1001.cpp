// A1001.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=a+b;
	if(c<0){
		printf("-");
		c=0-c;
	} 
	char zhan[20]={0};
	int k=0;
	int time=1;
	if(c==0) printf("0");
	else{
		while(c!=0){
		zhan[k++]=c%10+'0';
		c/=10;
		if(time%3==0)
			zhan[k++]=',';
		time++;
		}
		if(zhan[k-1]==',') k--;
		for(int i=k-1;i>=0;i--){
			printf("%c",zhan[i]);
		}	
	}
	return 0;
}

