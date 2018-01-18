// A1037.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
int nc[100010];
int np[100010];
using namespace std;
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&nc[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&np[i]);
	}
	sort(nc,nc+n);
	sort(np,np+m);
	long long sum=0;
	for(int k=0;nc[k]<0&&np[k]<0;k++){
		sum+=nc[k]*np[k];
	}
	int p=n-1,q=m-1;
	while(nc[p]>0&&np[q]>0){
		sum+=nc[p]*np[q];
		p--;
		q--;
	}
	printf("%d",sum);
	return 0;
}

