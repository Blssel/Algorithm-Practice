// A1075.cpp : 定义控制台应用程序的入口点。
//

// A1055.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct testee{
	int id;
	int score[6];
	bool canrank;
	int total;
	int perfect;
}testees[10010];
bool cmp(testee a,testee b){
	if(a.total!=b.total) return a.total>b.total;
	else if(a.perfect!=b.perfect) return a.perfect>b.perfect;
	else return a.id<b.id;
}
int main()
{
	int n,k,m;
	int p[6];
	scanf("%d%d%d",&n,&k,&m);
	//初始化
	for(int i=0;i<=n;i++){
		for(int j=0;j<6;j++)
			testees[i].score[j]=-1;
		testees[i].canrank=false;
		testees[i].perfect=0;
		testees[i].total=-1;
	}
	//
	for(int i=1;i<=k;i++){
		scanf("%d",&p[i]);
	}
	//
	for(int i=1;i<=m;i++){
		int tmp_id, tmp_tihao, tmp_score;
		scanf("%d %d %d",&tmp_id,&tmp_tihao,&tmp_score);
		if(tmp_score==-1){//如果编译未通过
			testees[tmp_id].score[tmp_tihao]=0;
		} 
		else if(tmp_score>=testees[tmp_id].score[tmp_tihao]){
			testees[tmp_id].canrank=true;
			testees[tmp_id].score[tmp_tihao]=tmp_score;
		}
	}
	//计算总分
	for(int i=1;i<=n;i++){
		testees[i].id=i;
		if(testees[i].canrank==false) continue;
		testees[i].total=0;
		for(int j=1;j<=k;j++){
			if(testees[i].score[j]!=-1){
				testees[i].total+=testees[i].score[j];
				if(testees[i].score[j]==p[j])//统计满分数量
					testees[i].perfect++;
			}
				
		}
	}
	//排序
	sort(testees+1,testees+n+1,cmp);
	//输出
	int previous;
	int zongrenshu=1;
	for(int i=1;i<=n;i++){
		if(testees[i].canrank==false){
			zongrenshu++;
		}else{
			//先打印名次
			if(testees[i].total==testees[i-1].total){
				zongrenshu++;
				printf("%d ",previous);//打印名次
			}else{
				printf("%d ",zongrenshu);
				previous=zongrenshu;
				zongrenshu++;
			}
			//再打印剩余信息
			printf("%05d %d",testees[i].id,testees[i].total);//id和总分
			for(int j=1;j<=k;j++){
				if(testees[i].score[j]==-1) printf(" -");
				else printf(" %d",testees[i].score[j]);
			}
			printf("\n");
		}
	}
	return 0;
}


