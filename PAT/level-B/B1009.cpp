// B1009.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
int main()
{
	char str[90];
	gets(str);
	int len = 0;
	while (str[len] != '\0')
		len++;
	char zhan[100];
	int p = 0;
	for (int i = len - 1; i >= -1; i--){
		if (str[i] != ' '&&i != -1){
			zhan[p++] = str[i];
		}
		else{
				printf("%c", zhan[k]);
			}
			if (i != -1) printf(" ");
			p = 0;
		}
	}
	return 0;
}

