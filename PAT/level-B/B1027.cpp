// B1027.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cstdio>

int main()
{
	int n;
	char cc;
	int sum = 1; int lev=1;
	scanf("%d %c", &n, &cc);
	while (sum * 2 - 1 < n&&(sum+lev+2)*2-1<n){
		lev+=2;
		sum += lev;
	}
	if ((sum + lev + 2) * 2 - 1 == n){
		lev = lev + 2;
		sum += lev;
	}
	int sp=0;//ÿ����Ҫ��ӡ�Ŀո���
	//��ӡ��������
	for (int i = lev; i >= 1; i-=2){
		int p = sp; int q = sp;
		sp++;//���������һ�У���ո�����һ
		//��ӡǰ���ո�
		while (p > 0){
			printf(" ");
			p--;
		}
		//��ӡͼ��
		for (int k = 0; k < i; k++){
			printf("%c", cc);
		}
		//��ӡ�󷽿ո�
		/*while (q > 0){//��ӡǰ���ո�
			printf(" ");
			q--;
		}*/
		//���У�׼����ӡ��һ��
		printf("\n");
	}
	//��ӡ��������
	if (lev > 1){
		int sp2 = lev/2-1;
		for (int i = 3; i <= lev; i += 2){
			int p2 = sp2; int q2 = sp2;
			sp2--;
			while (p2 > 0){
				printf(" ");
				p2--;
			}
			for (int k = 0; k < i; k++){
				printf("%c", cc);
			}
			/*while (q2>0){
				printf(" ");
				q2--;
			}*/
			printf("\n");
		}
	}

	printf("%d", n-(sum* 2 - 1));
	
	return 0;
}

