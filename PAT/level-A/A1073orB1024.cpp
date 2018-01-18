// A1073orB1024.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	char sci[25000];
	gets(sci);
	int len=0;
	for(;len<25000;len++){
		if(sci[len]=='\0')
			break;
	}
	int e=0;int t=1;		
	for(int i=len-1;sci[i]!='+'&&sci[i]!='-';i--){
		e+=(sci[i]-'0')*t;
		t*=10;
	}
	int j=len-1;//J指向阶码的符号
	while(sci[j]!='+'&&sci[j]!='-'){
		j--;
	}
	//如果是负数就先打印符号，否则省略正好
	if(sci[0]=='-'){
		printf("-");
	}
	//如果是负数
	if(sci[j]=='-'){
		printf("0.");
		for(int i=0;i<e-1;i++){
			printf("0");
		}  
		printf("%c",sci[1]);
		for(int i=3;i<j-1;i++){
			printf("%c",sci[i]);
		}
	}else{	//如果是正数
		int ee = e;
		if(e<=j-4){
			printf("%c",sci[1]);
			int k=3;
			for(;ee>0;k++){
				printf("%c",sci[k]);
				ee--;
			}
			if(e!=j-4)
				printf(".");
			for(int i=k;i<j-1;i++){
				printf("%c",sci[i]);
			}
		}else{
			for(int i=1;i<j-1;i++){
				if(sci[i]!='.')
					printf("%c",sci[i]);
			}
			for(int i=0;i<e-(j-4);i++)
				printf("0");
		}
		

	}
	return 0;
}

