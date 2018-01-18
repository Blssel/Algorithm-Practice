// A1092.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
int shop[256];
int eva[256];
int main()
{
	memset(shop,0,sizeof(shop));
	memset(eva,0,sizeof(eva));
	char str1[1010];
	char str2[1010];
	gets(str1);
	gets(str2);	
	int len1,len2;
	len1=strlen(str1);
	len2=strlen(str2);
	for(int i=0;i<len1;i++){
		shop[str1[i]]++;
	}
	for(int i=0;i<len2;i++){
		eva[str2[i]]++;
	}

	bool ok=true;
	int extra=0;
	int missing=0;
	for(int i=0;i<256;i++){
		if(eva[i]>0&&shop[i]<eva[i]){
			ok=false;
			break;
		}
	}
	if(ok==true){
		for(int i=0;i<256;i++){
			extra+=(shop[i]-eva[i]);
		}
		printf("Yes %d",extra);
	}else{
		for(int j=0;j<256;j++){
			if(eva[j]>0&&eva[j]>shop[j])
				missing+=eva[j]-shop[j];
		}
		printf("No %d",missing);
	}
	return 0;
}

