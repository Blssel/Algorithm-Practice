// A1031.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	char str[10000];
	scanf("%s", str);
	int len=0;//记录字符串长度
	while (str[len] != '\0'){
		len++;
	}
	int bottom=3;
	int vertical;
	for (int i = 0; i < len; i++){
		if ((len - bottom) % 2 == 0 && (len - bottom + 2) / 2>=bottom && (len - bottom) / 2 <= bottom + 2)
			break;
		bottom++;
	}
	if ((len - bottom + 2) / 2 != bottom)
		bottom += 2;
	printf("%d\n", bottom);
	int p1 = 0;
	int p2 = (len - bottom) / 2;
	int q1 = len - 1;
	int mid = p2;
	for (int i = 0; i < p2; i++){
		printf("%c", str[p1++]);
		for (int j = 0; j < bottom - 2; j++)
			printf(" ");
		printf("%c\n", str[q1--]);
	}
	for (int i = 0; i < bottom; i++){
		printf("%c", str[mid++]);
	}

	return 0;
}

