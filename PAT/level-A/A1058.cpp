// A1058.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
const long long  GALLEON = 17 * 29;
const long long SICKLES = 29;
int main()
{
	long long g1, s1, k1;
	long long g2, s2, k2;
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &g1, &s1, &k1, &g2, &s2, &k2);
	long long sum1, sum2,sum;
	sum1 = g1*GALLEON + s1*SICKLES+k1;
	sum2 = g2*GALLEON + s2*SICKLES+k2;
	sum = sum1 + sum2;
	printf("%lld.%lld.%lld\n", sum / GALLEON, sum%GALLEON / SICKLES, sum%SICKLES);
	return 0;
}
