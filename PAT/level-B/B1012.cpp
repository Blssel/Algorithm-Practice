// B1012.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
int a[1001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int a1 = 0; 
	int  a2 = 0; int num2 = 0;
	int  a3 = 0;
	double  a4 = 0; int num4 = 0; int sum4 = 0;
	int a5 = 0;
	int x = 1;//交错级数的符号调节
	for (int j = 0; j < n; j++){
		if (a[j] % 5 == 0){
			if (a[j] % 2 == 0) a1 += a[j];
		}


		if (a[j] % 5 == 1){
			num2++;
			a2 += a[j] * x;
			x = x*(-1);
		}

		if (a[j] % 5 == 2){
			a3++;
		}

		if (a[j] % 5 == 3){
			sum4 += a[j];
			num4++;
		}

		if (a[j] % 5 == 4){
			if (a[j] > a5){
				a5 = a[j];
			}
		}
	}
	a4 = (double)sum4 / (double)num4;
	if (a1 == 0) printf("N ");
	else printf("%d ", a1);
	if (num2 == 0) printf("N ");
	else printf("%d ", a2);
	if (a3 == 0) printf("N ");
	else printf("%d ", a3);
	if (num4 == 0) printf("N ");
	else printf("%.1f ", a4);
	if (a5 == 0) printf("N\n");
	else printf("%d\n", a5);
	return 0;
}

