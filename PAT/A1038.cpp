// A1038.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,p;
	int seq[100010];
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&seq[i]);
	}
	sort(seq,seq+n);
	int ans=0;
	for(int i=0;i<n-1;i++){
		long long tmp=seq[i]*p;
		int j=upper_bound(seq+i+1,seq+n,tmp)-seq;
		ans=max(ans,j-i);
	}
	printf("%d",ans);

	return 0;
}

