// A1011.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	double	table[3][3];
	double max[3];//ÿ��λ�ô�Ŷ�Ӧ���ε����ֵ
	char rel[3] = { 'W', 'T', 'L' };
	int select[3];//ѡ������������
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			scanf("%lf", &table[j]);
			if (*table[j]> max[i]){
				max[i] = *table[j];
				select[i] = j;
			}
		}
	}
	double profit;
	profit = (max[0] * max[1] * max[2] * 0.65 - 1) * 2;
	printf("%c %c %c %.2lf", rel[select[0]], rel[select[1]], rel[select[2]], profit);

	return 0;
}
