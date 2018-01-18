// A1055.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct person{
	char name[10];
	int age;
	int	networth;
}people[100010];
struct query{
	int max;
	int amin,amax;
}queries[1100];
bool cmp(person a,person b){
	if(a.networth !=b.networth ) return a.networth >b.networth ;
	else if(a.age !=b.age ) return a.age <b.age ;
	else return strcmp(a.name ,b.name )<0;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s %d %d",people[i].name,&people[i].age,&people[i].networth);
	}
	for(int i=0;i<k;i++){
		scanf("%d %d %d",&queries[i].max,&queries[i].amin,&queries[i].amax);
	}
	//
	sort(people,people+n,cmp);
	//
	for(int i=0;i<k;i++){
		printf("Case #%d:\n",i+1);
		bool exist=false;
		int remind=queries[i].max; 
		for(int j=0;j<n;j++){
			if(people[j].age>=queries[i].amin&&people[j].age<=queries[i].amax){
				if(remind>0){
					printf("%s %d %d\n",people[j].name,people[j].age,people[j].networth);
					exist=true;
					remind--;	
				}
				else{
					break;
				}
			}
		}//for
		if(exist==false){
			printf("None\n");
		}
	}
	return 0;
}

