// A1019.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	int n, b;
	scanf("%d%d", &n, &b);
	int trans[50];
	int i = 0;
	do{
		trans[i++]=n%b;
		n /= b;
	} while (n != 0);
	int p = 0; int q = i - 1;
	int flag = 1;
	while (p <= q){
		if (trans[p] != trans[q]){
			flag = 0;
			break;
		}
		p++; q--;
	}
	if (flag == 0) printf("No\n");
	else printf("Yes\n");
	for (int j = i-1; j >=0; j--){
		printf("%d", trans[j]);
		if (j !=0) printf(" ");
	}
	printf("\n");
	return 0;
}

