// B1010.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cstdio>
int  mul[1010] = {0};
int main()
{
	int x; int e;

	while (scanf("%d%d",&x,&e)!=EOF){
		mul[e] = x;
	}
	for (int i = 1; i < 1010; i++){
		mul[i] = mul[i] * i;
	}
	int min=0;//�����С���λ��
	for (int k = 0; k < 1010; k++){
		if (mul[k] != 0){
			min = k;
			break;
		}
	}

	if (min == 1009) printf("%d %d",0,0);
	else{
		for (int i = 1009; i >= min; i--){
			if (mul[i] != 0){
				printf("%d %d", mul[i], i - 1);
			}
			if (i != min) printf(" ");
		}
	}
	

	return 0;
}

