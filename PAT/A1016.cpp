// A1016.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct recode{
	char name[25];
	int mon; int  date;int hour;int min;
	long long time;
	char state[10];
}cstm[1100];
bool cmp1(recode a,recode b){
	return strcmp(a.name ,b.name )<0;
}
bool cmp2(recode a,recode b){
	return a.time<b.time;
}
int main()
{
	/*int toll[24];
	for(int i=0;i<24;i++){
		scanf("%d",&toll[i]);
	}*/
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d:%d %s",cstm[i].name ,cstm[i].mon ,cstm[i].date,
									cstm[i].hour ,cstm[i].min ,cstm[i].state );
		cstm[i].time=cstm[i].min+cstm[i].hour*100+cstm[i].date*10000+cstm[i].mon*1000000;  
	}
	sort(cstm,cstm+n,cmp1);
	//开始
	int p=0;
	while(p!=n){
		int now=p;
		char tmp[25];
		strcpy(tmp,cstm[p].name);
		while(strcmp(cstm[p].name,tmp)){
			p++;
		}
		sort(cstm+now,cstm+p,cmp2);
		//
		int total=0;
		printf("%s %0d\n",cstm[now].name,cstm[now].mon);
		int start=now;
		int next=start+1;
		while(start<p&&next<p){
			if(strcmp(cstm[start].state,cstm[next].state)==false){
				printf("%0d:%0d%0d %0d:%0d%0d\n",cstm[start].date,cstm[start].hour,cstm[start].min
											  ,cstm[next].date,cstm[next].hour,cstm[next].min);
				//printf(" %d",cha(cstm[start].date,cstm[start].hour,cstm[start].min
					//		,cstm[next].date,cstm[next].hour,cstm[next].min));
				//重新定位start 和 next
				start+=2;
				while(start<p){
					if(strcmp(cstm[p].state,"on-line"))
						break;
					else
						start+=1;
				} 
				if(start<p){
					next=start+1;
					while(next<p){
						if(strcmp(cstm[next].state,"off-line"))
							break;
						else
							next+=1;
					}
				}
			}//if
		}//while
	}

	return 0;
}

