// A1035.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
char cname[1100][15]={0};
char cpsw[1100][15];
int main()
{
	int n;
	char name[15];
	char psw[15];
	scanf("%d",&n);
	int k=0;
	int N=n;
	while(N--!=0){
		scanf("%s %s",name,psw);
		for(int i=0;psw[i]!='\0';i++){
			if(psw[i]=='1'||psw[i]=='0'||psw[i]=='l'||psw[i]=='O'){	
				strcpy(cname[k],name);
				strcpy(cpsw[k],psw);
				k++;
				break;
			}
		}
		for(int i=0;cpsw[k-1][i]!='\0';i++){
			if(cpsw[k-1][i]=='1'||cpsw[k-1][i]=='0'||cpsw[k-1][i]=='l'||cpsw[k-1][i]=='O'){	
				if(cpsw[k-1][i]=='1')
					cpsw[k-1][i]='@';
				else if(cpsw[k-1][i]=='0')
					cpsw[k-1][i]='%';
				else if(cpsw[k-1][i]=='l')
					cpsw[k-1][i]='L';
				else if(cpsw[k-1][i]=='O')
					cpsw[k-1][i]='o';
			}
		}
	}
	if(k==0){
		if(n==1)
			printf("There is %d account and no account is modified\n",n);
		else
			printf("There are %d accounts and no account is modified\n",n);
	}
	else{
		printf("%d\n",k);
		for(int i=0;i<k;i++){
			printf("%s %s\n",cname[i],cpsw[i]);
		}	
	}
	
	return 0;
}



