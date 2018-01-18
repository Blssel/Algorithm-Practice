// B1016.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	long long A; long long DA; long long PA = 0;
	long long B; long long DB; long long PB = 0;
	scanf("%lld%lld%lld%lld", &A, &DA, &B, &DB);
	while (A){
		if (A%10== DA){
			PA = PA*10 + DA;
		}
		A = A / 10;
	}
	while (B){
		if (B%10 == DB){
			PB = PB*10 + DB;
		}
		B = B / 10;
	}
	printf("%lld\n", PA + PB);
	return 0;
}

