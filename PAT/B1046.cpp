// B1046.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	int n;
	int a1, a2, b1, b2;
	int wine_a = 0;int  wine_b=0;
	scanf("%d", &n);
	while (n--){
		scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
		if (a1 + b1 == a2&&a1 + b1 == b2) continue;
		if (a1 + b1 == a2) wine_b++;
		if (a1 + b1 == b2) wine_a++;
	}
	printf("%d %d\n", wine_a, wine_b);
	return 0;
}

