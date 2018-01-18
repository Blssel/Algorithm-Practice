// A1042.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	int k;
	int order[55];
	int init[55];
	int tmp[55];
	for (int i = 1; i <=54; i++){
		init[i] = i-1;
	}
	scanf("%d", &k);
	for (int j = 1; j <=54; j++){
		scanf("%d", &order[j]);
	}
	int now;//当前
	while (k--){
		for (int m = 1; m <= 54; m++){
			now = order[m];
			tmp[now] = init[m];
		}
		for (int n = 1; n <= 54; n++){
			init[n] = tmp[n];
		}
	}
	char flower; int num;
	for (int p = 1; p <= 54; p++){
		if (init[p] >=52) flower = 'J';
		else if (init[p] / 13 == 0) flower = 'S';
		else if (init[p] / 13 == 1) flower = 'H';
		else if (init[p] / 13 == 2) flower = 'C';
		else if (init[p] / 13 == 3) flower = 'D';
		
		num = init[p] % 13 + 1;
		printf("%c%d", flower, num);
		if (p != 54) printf(" ");
	}
	
	return 0;
}

