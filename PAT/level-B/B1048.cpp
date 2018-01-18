// B1048.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	char a[110];
	char b[110];
	scanf("%s %s",a,b);
	int len_a=0,len_b=0;
	while(a[len_a]!='\0')
		len_a++;
	while(b[len_b]!='\0')
		len_b++;
	int p=len_a-1,q=len_b-1;
	int time=1;
	char zhan[110]={0};int k=0;
	while(p>=0&&q>=0){
		if(time%2==1){
			int tmp=((a[p]-'0')+(b[q]-'0'))%13;
			if(tmp==10)
				zhan[k++]='J';
			else if(tmp==11)
				zhan[k++]='Q';
			else if(tmp==12)
				zhan[k++]='K';
			else
				zhan[k++]=tmp+'0';
		}else{
			int tmp2=b[q]-a[p];
			if(tmp2<0)
				tmp2+=10;
			zhan[k++]=tmp2+'0';
		}
		p--;q--;
		time++;
	}
	while(q>=0){
		zhan[k++]=b[q];
		q--;
	}
	for(int i=k-1;i>=0;i--){
		printf("%c",zhan[i]);
	}
	printf("\n");
	return 0;
}

