// A1009.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cstdio>
const int L = 2500;
double a[L] = { 0.0 };
double b[L] = { 0.0 };
double c[L] = { 0.0 };
int main()
{

	int k1, k2;
	int e;
	double cc;
	//input
	scanf("%d", &k1);
	while (k1--){
		scanf("%d %lf", &e, &cc);//�˴�ʹ��f��
		a[e] = cc;
	}
	//input
	scanf("%d", &k2);
	while (k2--){
		scanf("%d %lf", &e, &cc);//�˴�ʹ��f��
		b[e] = cc;
	}
	//���
	for (int i = 0; i <= L - 1; i++){
		for (int j = 0; j <= L - 1; j++)
			c[i + j] = c[i + j]+ a[i] * b[j];
	}
	//ͳ������
	double zero = 0.0; int num = 0;
	for (int i = 0; i <= L - 1; i++){
		if (c[i] != zero) num++;
	}
	//���
	printf("%d", num);
	for (int i = L - 1; i >= 0; i--){
		if (c[i] != zero){
			printf(" %d %.1f", i, c[i]);
		}
	}

	return 0;
}