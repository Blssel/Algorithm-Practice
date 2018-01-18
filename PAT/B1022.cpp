// B1022.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	int a, b, d, sum;
	int stc[50]; int i = 0;
	scanf("%d%d%d", &a, &b, &d);
	sum = a + b;
	do{
		stc[i++]=sum%d;
		sum /= d;
	} while (sum != 0);
	for (int j = i-1; j >=0;j--){
		printf("%d", stc[j]);
	}
	printf("\n");
	return 0;
}

