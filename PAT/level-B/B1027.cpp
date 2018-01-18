// B1027.cpp : 定义控制台应用程序的入口点。
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
	int sp=0;//每行需要打印的空格数
	//打印上面三角
	for (int i = lev; i >= 1; i-=2){
		int p = sp; int q = sp;
		sp++;//如果还有下一行，则空格数加一
		//打印前方空格
		while (p > 0){
			printf(" ");
			p--;
		}
		//打印图案
		for (int k = 0; k < i; k++){
			printf("%c", cc);
		}
		//打印后方空格
		/*while (q > 0){//打印前方空格
			printf(" ");
			q--;
		}*/
		//换行，准备打印下一行
		printf("\n");
	}
	//打印下面三角
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

