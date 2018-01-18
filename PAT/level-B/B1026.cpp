// B1026.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<math.h>
const int CLK_TCK = 100;
int main()
{
	int c1; int c2;
	double d_value; int time;
	int hour; int minute; int second;
	scanf("%d%d", &c1, &c2);

	d_value = (double)(c2 - c1) / (double)CLK_TCK;//
	time =(int)round(d_value);

	hour = time / 3600;
	time %= 3600;
	minute = time / 60;
	time %= 60;
	second = time;
	printf("%02d:%02d:%02d\n", hour, minute, second);
	return 0;
}

