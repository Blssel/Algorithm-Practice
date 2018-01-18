// B1008.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	int n; int m;
	int a[101];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int tmp;
	while (m--){
		tmp = a[n - 1];
		for (int j = n - 2; j >= 0; j--){
			a[j + 1] = a[j];
		}
		a[0] = tmp;
	}

	for (int k = 0; k <=n-2; k++){
		printf("%d ", a[k]);		
	}
	printf("%d\n", a[n - 1]);
	return 0;
}

