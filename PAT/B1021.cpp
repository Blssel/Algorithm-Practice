// B1021.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	int times[10] = {0};
	char n[1100];
	scanf("%s", n);
	int len = 0;
	while (n[len] != '\0'){
		len++;
	}
	for (int i = 0; i < len; i++){
		times[n[i] - '0']++;
	}
	for (int j = 0; j < 10; j++){
		if (times[j] != 0){
			printf("%d:%d\n", j, times[j]);
		}
	}

	return 0;
}

