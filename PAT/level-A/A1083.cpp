// A1083.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct person{
	char name[15];
	char id[15];
	int grade;
}student[150];
bool cmp(person a,person b){
	return a.grade>b.grade;
}
int main()
{
	int n,grade1,grade2;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %s %d",student[i].name,student[i].id,&student[i].grade);
	}
	scanf("%d%d",&grade1,&grade2);
	sort(student,student+n,cmp);
	bool exist=false;
	for(int i=0;i<n;i++){
		if(student[i].grade>=grade1&&student[i].grade<=grade2){
			printf("%s %s\n",student[i].name,student[i].id);
			exist=true;
		}
	}
	if(exist==false){
		printf("NONE\n");
	}
	return 0;
}

