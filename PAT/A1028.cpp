// A1028.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct stu{
	char id[10];
	char name[10];
	int grade;
}student[100010];
bool cmp1(stu a,stu b){
	return strcmp(a.id,b.id)<0;
}
bool cmp2(stu a,stu b){
	if(strcmp(a.name,b.name)!=0)
		return strcmp(a.name,b.name)<0;
	else
		return strcmp(a.id,b.id)<0;
}
bool cmp3(stu a,stu b){
	if(a.grade!=b.grade) return a.grade <b.grade ;
	else return strcmp(a.id,b.id)<0;
}
int main()
{
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++){
		scanf("%s %s %d",student[i].id,student[i].name,&student[i].grade);
	}
	if(c==1) sort(student,student+n,cmp1);
	else if(c==2) sort(student,student+n,cmp2);
	else sort(student,student+n,cmp3);
	for(int i=0;i<n;i++){
		printf("%s %s %d\n",student[i].id,student[i].name,student[i].grade);
	}
	return 0;
}

