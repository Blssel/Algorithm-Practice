// B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
char str[1010];
int hash[256];
int main()
{
	memset(hash,0,sizeof(hash));
	gets(str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]>='A'&&str[i]<='Z'){
			char low=str[i]-'A'+'a';
			hash[low]++;
		}else{
			hash[str[i]]++;
		}
	}
	int max=0;
	for(int i='a';i>='a'&&i<='z';i++){
		if(hash[i]>hash[max])
			max=i;
	}
	printf("%c %d",max,hash[max]);
	return 0;
}

