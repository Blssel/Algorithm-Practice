// A1077.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
char word[110][300];
void reverse(char a[110][300],int n){
	char b[110][300];
	for(int i=0;i<n;i++){
		int k=0;
		for(int j=(strlen(a[i])-1);j>=0;j--){
			b[i][k++]=a[i][j];
		}
		b[i][k++]='\0';
	}
	for(int i=0;i<n;i++){
		for(int j=0;b[i][j]!='\0';j++){
			a[i][j]=b[i][j];
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		gets(word[i]);
	}
	//printf("%s\n\n",word[0]);
	reverse(word,n);
	//printf("%s\n\n",word[0]);
	char temp[300];
	int p=0;
	for(p;;p++){
		bool flag=true;
		char tmp=word[0][p];
		if(tmp=='\0') break;
		for(int i=0;i<n;i++){
			if(word[i][p]==tmp){
				temp[p]=word[i][p];
			}
			else{
				flag=false;
			}
		}
		if(flag==false)
			break;
	}
	if(p==0){
		printf("nai\n");
	}
	else{
		for(int i=p-1;i>=0;i--){
			printf("%c",temp[i]);
		}	
	}
	
	return 0;
}

