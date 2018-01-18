// A1010.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
long long toDecimal(char a[],int r){//将r进制数转换成10进制数
	//求长度
	int len = 0;
	while (a[len] != '\0') len++;
	//
	long long dec=0;
	int lev = 1;
	for (int i = len - 1; i >= 0; i--){
		if (a[i] >= 'a') dec = dec + (a[i] - 'a' + 10)*lev;
		else dec = dec + (a[i] - '0')*lev;
		lev = lev*r;
	}
	return dec;
}
int maxRadix(char a[]){
	int i = 0;
	int max=0; int tmp;
	while (a[i] != '\0'){
		if (a[i] >= 'a'){
			tmp = a[i] - 'a' + 10;
			if (tmp > max) max = tmp;
		} 
		else{
			tmp = a[i] - '0';
			if (tmp > max) max = tmp;
		}
		i++;
	}
	return max + 1;

}
int main()
{
	char n1[11];
	char n2[11];
	int tag; int radix;
	scanf("%s", n1);
	scanf("%s", n2);
	scanf("%d", &tag);
	scanf("%d", &radix);
	long long dec1, dec2;
	int flag = 0;
	if (tag == 1){
		dec1 = toDecimal(n1, radix);
		//确定另一个数的可能进制的最小值
		int min = maxRadix(n2);
		for (int i = min; i <= 36; i++){
			dec2 = toDecimal(n2, i);
			if (dec2 == dec1){
				printf("%d\n", i);
				flag = 1;
				break;
			}
			else if (dec2 > dec1){
				printf("Impossible\n");
				flag = 1;
				break;
			}
		}
		if (flag == 0) printf("Impossible\n");
	} 

	if (tag == 2){
		dec2 = toDecimal(n2, radix);
		//确定另一个数的可能进制的最小值
		int min = maxRadix(n1);
		for (int i = min; i <= 36; i++){
			dec1 = toDecimal(n1, i);
			if (dec1 == dec1){
				printf("%d\n", i);
				flag = 1;
				break;
			}
			else if (dec1 > dec2){
				printf("Impossible\n");
				flag = 1;
				break;
			}
		}
		if (flag == 0) printf("Impossible\n");
	}
	return 0;
}

