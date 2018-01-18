// A1082.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
char chinese[10][5]={{"ling"},{"yi"},{"er"},{"san"},{"si"},{"wu"},{"liu"},{"qi"},{"ba"},{"jiu"}};
char wei[6][5]={{"Qian"},{"Bai"},{"Shi"},{""}};
int main()
{
	char input[15];
	gets(input);
	if(input[0]=='-'){
		printf("Fu ");
		int i=1;
		for(i;input[i]!='\0';i++){
			input[i-1]=input[i];
		}
		input[i-1]=input[i];
	}
	int k=0;//贯穿始终
	if(strlen(input)==9){
		printf("%s Yi ",chinese[input[k]-'0']);
		int j=1;
		for(j;input[j]!='\0';j++){
			input[j-1]=input[j];
		}
		input[j-1]=input[j];
	}
	
	//
	if(strlen(input)>4){
		int m=4-(strlen(input)-4);
		for(k;k<=strlen(input)-5;){
			if(input[k]=='0'){
				while(input[k]=='0'&&k<=strlen(input)-5){
					k++;
					m++;
				}
				if(k!=strlen(input)-4)
					printf("ling ");
			}
			else{
				printf("%s %s",chinese[input[k]-'0'],wei[m]);
				if(m!=3) printf(" ");
				k++;
				m++;
			}
		}
			printf("Wan ");
			
	}
	//
	if(strlen(input)==1){
		printf("%s",chinese[input[0]-'0']);
	}else{
		int x;
	if(strlen(input)>4){
		x=0;
	}else{
		x=4-strlen(input);
	}
	if(input[k]=='0'){
		while(input[k]=='0'&&k<strlen(input)){
			k++;
			x++;
		}
		printf("ling");
		if(k!=strlen(input)-1)
			printf(" ");
	}

	//
	for(k;k<strlen(input);){
			if(input[k]=='0'){
				while(input[k]=='0'&&k<=strlen(input)-1){
					k++;
					x++;
				}
				if(k!=strlen(input)){
					printf("ling ");
				}
					
			}
			else{
				printf("%s",chinese[input[k]-'0']);
				if(k!=strlen(input)-1) printf(" ");
				printf("%s",wei[x]);
				bool allzero=true;
				for(int i=k+1;i<strlen(input);i++){
					if(input[i]!='0'){
						allzero=false;
						break;
					}
				}
				if(allzero==false) printf(" ");
				k++;
				x++;
			}
		}
	}
	
	return 0;
}

