// A1048.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
int hash[501];
int main()
{
	memset(hash,0,sizeof(hash));
	int n,m;
	scanf("%d%d",&n,&m);
	int nn=n;
	while(nn--){
		int tmp;
		scanf("%d",&tmp);
		hash[tmp]++;
	}
	bool exist=false;
	for(int i=1;i<501;i++){
		if(hash[i]>0){
			hash[i]--;
			for(int j=i;j<501;j++){
				if(hash[j]>0){
					if((i+j)>m) break;
					else if((i+j)==m){
						exist=true;
						printf("%d %d",i,j);
						break;
					}
				}
			}
		}
		if(exist==true) break;
	}
	if(exist==false) printf("No Solution");
	return 0;
}

