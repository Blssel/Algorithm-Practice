

#include "stdafx.h"
#include<cstdio>
typedef struct {
	long long exm;
	int cmp;
	int seat;
}examinee ;
int main()
{
	examinee stu[1100];
	int n,m;
	int srch[1100];//需要查询的机器号存放在srch中
	scanf("%d", &n);
	for (int i = 0; i < n;i++){
		scanf("%lld%d%d", &stu[i].exm, &stu[i].cmp, &stu[i].seat);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d", &srch[i]);
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (srch[i]==stu[j].cmp){
				printf("%lld %d\n", stu[j].exm, stu[j].seat);
			}
		}
	}

	return 0;
}

