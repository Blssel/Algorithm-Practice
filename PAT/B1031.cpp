// B1031.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cstdio>
int  weight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
char m[11] = { '1', '0', 'X', '9', '8', '7', '6','5','4','3','2' };
int main()
{
	int n;
	scanf("%d", &n); 
	char id[19];
	int flag = 1;//��ʼ����
	while (n--){
		int sum = 0;
		scanf("%s", id);
		for (int i = 0; i < 17; i++){
			sum += (id[i] - '0')*weight[i];
		}
		int z = sum % 11;
		if (m[z] != id[17]){
			printf("%s\n", id);
			flag = 0;
		}
	}
	if (flag == 1) printf("All passed\n");
	return 0;
}

