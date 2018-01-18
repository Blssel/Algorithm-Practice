// B1033.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
char broken[100010];

int main()
{
	bool hash[256];
	memset(hash,true,sizeof(hash));
	gets(broken);
	int len=strlen(broken);
	for(int i=0;i<len;i++){
		if(broken[i]>='A'&&broken[i]<='Z'){
			hash[broken[i]+32]=false;
		}else{
			hash[broken[i]]=false;
		}
	}
	gets(broken);
	len=strlen(broken);
	for(int i=0;i<len;i++){
		if(broken[i]>='A'&&broken[i]<='Z'){
			if(hash['+']==true&&hash[broken[i]+32]==true){
				printf("%c",broken[i]);
			}
		}
		//
		else{
			if(hash[broken[i]]==true){
				printf("%c",broken[i]);
			}
		}
	}
	//
		printf("\n");

	return 0;
}
/*
const int maxn=100010;
bool hash[256];
char str[maxn];
int main(){
	memset(hash,true,sizeof(hash));
	gets(str);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]>='A'&&str[i]<='Z'){
			str[i]=str[i]-'A'+'a';
		}
		hash[str[i]]=false;
	}
	gets(str);
	len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]>='A'&&str[i]<='Z'){
			int low=str[i]-'A'+'a';
			if(hash[low]==true&&hash['+']==true){
				printf("%c",str[i]);
			}
		}else if(hash[str[i]]==true){
			printf("%c",str[i]);
		}
	}
	printf("\n");
	return 0;
}*/