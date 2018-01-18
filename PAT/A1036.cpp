// A1036.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
struct student{
	char name[15];
	char gender;
	char id[15];
	int grade;
}tmp,highest_fel,lowest_mal;
int main()
{
	highest_fel.grade = -1;
	lowest_mal.grade = 101;
	int n;
	scanf("%d", &n);
	while (n--){
		scanf("%s %c %s %d", tmp.name, &tmp.gender, tmp.id, &tmp.grade);
		if (tmp.gender == 'M'){
			if (tmp.grade < lowest_mal.grade) lowest_mal = tmp;
		}
		else{
			if (tmp.grade>highest_fel.grade) highest_fel = tmp;
		}
	}
	if (highest_fel.grade == -1) printf("Absent\n");
	else printf("%s %s\n", highest_fel.name, highest_fel.id);
	if (lowest_mal.grade == 101) printf("Absent\n");
	else printf("%s %s\n", lowest_mal.name, lowest_mal.id);
	if (highest_fel.grade == -1 || lowest_mal.grade == 101){
		printf("NA\n");
	}
	else printf("%d\n", highest_fel.grade - lowest_mal.grade);
	return 0;
}

