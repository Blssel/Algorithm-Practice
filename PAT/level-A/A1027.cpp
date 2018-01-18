// A1027.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
void toMar(int x,char mar[], int &i){
	do{
		if (x % 13 > 9) mar[i++] = x % 13 - 10 + 'A';
		else mar[i++] = x % 13+'0';
		x /= 13;
	} while (x != 0);
	for (int j = i - 1; j >= 0; j--){
		if (i == 1) printf("0");
		printf("%c", mar[j]);
	}
	i = 0;
}
int main()
{
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	char mar[10];
	int i = 0;
	printf("#");
	toMar(r, mar, i);
	toMar(g, mar, i);
	toMar(b, mar, i);
	printf("\n");
	return 0;
}

