// A1065.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	long long a, b, c;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld%lld%lld", &a, &b, &c);
		long long ans = a + b;
		if (a > 0 && b > 0 && ans < 0) printf("Case #%d: true\n",i);
		else if (a < 0 && b<0 && ans>0) printf("Case #%d: false\n", i);
		else if (ans>c) printf("Case #%d: true\n", i);
		else  printf("Case #%d: false\n", i);
	}
	
	return 0;
}
