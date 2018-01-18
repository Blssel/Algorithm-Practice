// B1043.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
char PATest[7]="PATest";
char str[10010];
int hash[6];
int main()
{
	memset(hash,0,sizeof(hash));
	gets(str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		for(int j=0;j<6;j++){
			if(str[i]==PATest[j]){
				hash[j]++;
				break;
			}
		}
	}
	int max=0;
	for(int i=0;i<6;i++){
		if(hash[i]>max)
			max=hash[i];
	}
	while(max--!=0){
		for(int i=0;i<6;i++){
			if(hash[i]>0){
				printf("%c",PATest[i]);
				hash[i]--;
			}
		}
	}
	
	return 0;
}

