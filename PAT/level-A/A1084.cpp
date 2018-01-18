// A1084.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
int main()
{
	int letter[30];
	int digit[15];
	int space=-1;
	for(int i=0;i<30;i++){
		letter[i]=-1;
	}
	for(int i=0;i<15;i++){
		digit[i]=-1;
	}
	char str1[85];
	char str2[85];
	gets(str1);
	gets(str2);
	for(int i=0;i<strlen(str1);i++){
		if(str1[i]>='0'&&str1[i]<='9'){
			digit[str1[i]-'0']=0;
		}
		if(str1[i]>='a'&&str1[i]<='z'){
			letter[str1[i]-'a']=0;
		}
		if(str1[i]>='A'&&str1[i]<='Z'){
			letter[str1[i]-'A']=0;
		}
		if(str1[i]=='_'){
			space=0;
		}
	}
	for(int i=0;i<strlen(str2);i++){
		if(str2[i]>='0'&&str2[i]<='9'){
			digit[str2[i]-'0']=-1;
		}
		if(str2[i]>='a'&&str2[i]<='z'){
			letter[str2[i]-'a']=-1;
		}
		if(str2[i]>='A'&&str2[i]<='Z'){
			letter[str2[i]-'A']=-1;
		}
		if(str2[i]=='_'){
			space=-1;
		}
	}
	//
	for(int i=0;i<strlen(str1);i++){
		if(str1[i]>='0'&&str1[i]<='9'){
			if(digit[str1[i]-'0']==0){
				printf("%c",str1[i]);
				digit[str1[i]-'0']=-1;
			}
		}
		if(str1[i]>='a'&&str1[i]<='z'){
			if(letter[str1[i]-'a']==0){
				printf("%c",str1[i]+('A'-'a'));
				letter[str1[i]-'a']=-1;
			}
		}
		if(str1[i]>='A'&&str1[i]<='Z'){
			if(letter[str1[i]-'A']==0){
				printf("%c",str1[i]);
				letter[str1[i]-'A']=-1;
			}
		}
		if(str1[i]=='_'){
			if(space==0){
				printf("_");
				space=-1;
			}
		}
	}
	return 0;
}

