// A1005.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
char num[11][10]={{"zero"},{"one"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"}};
int main()
{
	char n[110];
	scanf("%s",n);
	int len=0;
	/*
	for(int i=0;i<110;i++){
		if(n[i]!='\0') len++;
		else break;
	}
	*/
	int sum=0;
	for(int i=0;n[i]!='\0';i++){
		sum+=(n[i]-'0');
	}
	if(sum==0) printf("zero");
	else{
		int zhan[100];int k=0;
		while(sum!=0){
			zhan[k++]=sum%10;
			sum/=10;
		}
		for(int i=k-1;i>=0;i--){
			printf("%s",num[zhan[i]]);
			if(i!=0) printf(" ");
		}
		printf("\n");	
	}
	return 0;
}

