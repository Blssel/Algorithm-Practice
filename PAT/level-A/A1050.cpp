// A1050.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
char str1[10010];
char str2[10010];
bool hash[256];
int main()
{
	memset(hash,false,sizeof(hash));
	gets(str1);
	gets(str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len2;i++){
		hash[str2[i]]=true;
	}
	for(int i=0;i<len1;i++){
		if(hash[str1[i]]==false){
			printf("%c",str1[i]);
		}
	}
	return 0;
}

