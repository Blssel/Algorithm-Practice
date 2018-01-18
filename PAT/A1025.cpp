// A1025.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct testee{
	char rgst_num[16];
	int score;
	int location_num;
	int local_rank;
	int final_rank;
}testees[30100];
//cmp
bool cmp(testee a,testee b){
	if(a.score!=b.score) return a.score>b.score;
	else return strcmp(a.rgst_num,b.rgst_num)<0;
}
int main()
{
	int n,k,total_num=0;
	scanf("%d",&n);
	int begin=0;//
	int end=0;//指向testees数组
	int loc_num=1;//考场编号
	int total_rnk=1;//总排名
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		int kk=0;
		total_num+=k;
		while(kk++<k){
			scanf("%s %d",testees[end].rgst_num,&testees[end].score);
			testees[end].location_num=loc_num; 
			end++;
		}
		loc_num++;
		//
		sort(testees+begin,testees+end,cmp);
		//
		testees[begin].local_rank=1;
		for(int x=begin+1;x<end;x++){
			if(testees[x].score==testees[x-1].score){
				testees[x].local_rank=testees[x-1].local_rank;
			}else
				testees[x].local_rank=x+k-total_num+1;
		}
		//
		begin=end;
	}
	//进行总排名
	sort(testees,testees+end,cmp);
	testees[0].final_rank=1;
	for(int y=1;y<end;y++){
		if(testees[y].score==testees[y-1].score){
			testees[y].final_rank=testees[y-1].final_rank;
		}else{
			testees[y].final_rank=y+1;
		}
	}
	//输出
	printf("%d\n",total_num);
	for(int z=0;z<end;z++){
		printf("%s %d %d %d\n",testees[z].rgst_num,testees[z].final_rank,testees[z].location_num,testees[z].local_rank);	
	}
	
	return 0;
}

