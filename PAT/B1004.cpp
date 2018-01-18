// B1004.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
typedef struct{
	char name[15];
	char id[15];
	int score;
}student;
int main()
{
	student  stu[101];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].score);
	}
	int max_score = 0; int max_loc;
	int min_score = 100; int min_loc;
	for (int i = 0; i < n; i++){
		if (stu[i].score>max_score){
			max_score = stu[i].score;
			max_loc = i;
		} 
		if (stu[i].score < min_score){
			min_score = stu[i].score;
			min_loc = i;
		} 
	}
	printf("%s %s\n", stu[max_loc].name, stu[max_loc].id);
	printf("%s %s\n", stu[min_loc].name, stu[min_loc].id);

	return 0;
}

