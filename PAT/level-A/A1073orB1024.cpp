// A1073orB1024.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int j=len-1;//Jָ�����ķ���
	while(sci[j]!='+'&&sci[j]!='-'){
		j--;
	}
	//����Ǹ������ȴ�ӡ���ţ�����ʡ������
	if(sci[0]=='-'){
		printf("-");
	}
	//����Ǹ���
	if(sci[j]=='-'){
		printf("0.");
		for(int i=0;i<e-1;i++){
			printf("0");
		}  
		printf("%c",sci[1]);
		for(int i=3;i<j-1;i++){
			printf("%c",sci[i]);
		}
	}else{	//���������
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

