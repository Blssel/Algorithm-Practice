// B1002.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	char n[110];
	gets(n);
	int len = 0;
	while (n[len] != '\0'){
		len++;
	}
	int sum = 0;
	for (int i = 0; i < len; i++){
		sum += n[i] - '0';
	}
	int chai[5];
	int i = 0;
	do{
		chai[i++] = sum % 10;
		sum /= 10;
	} while (sum != 0);
	for (int j = i - 1; j >= 0; j--){
		switch (chai[j]){
		case 0:
			printf("ling");
			break;
		case 1:
			printf("yi");
			break;
		case 2:
			printf("er");
			break;
		case 3:
			printf("san");
			break;
		case 4:
			printf("si");
			break;
		case 5:
			printf("wu");
			break;
		case 6:
			printf("liu");
			break;
		case 7:
			printf("qi");
			break;
		case 8:
			printf("ba");
			break;
		case 9:
			printf("jiu");
			break;
		}
		if (j != 0) printf(" ");
	}
	return 0;
}

