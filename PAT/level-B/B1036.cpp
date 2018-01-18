// B1036.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	int n;
	char cc;
	scanf("%d %c", &n, &cc);
	int line, row;
	row = n;//列数
	if (row % 2 == 0) line = row / 2;
	else line = row / 2 + 1;
	for (int i = 0; i < row; i++) printf("%c", cc);
	printf("\n");
	for (int i = 0; i < line - 2; i++){
		printf("%c", cc);
		for (int j = 0; j < row - 2; j++){
			printf(" ");
		}
		printf("%c\n", cc);
	}
	for (int i = 0; i < row; i++) printf("%c", cc);
	printf("\n");
	return 0;
}

