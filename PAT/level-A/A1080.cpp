// A1080.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct person{
	int id;
	int ge,gi;
	int avg;
	int zhiyuan[5];
	int rank;
	int received;//为-1表示未录取；否则号码对应
}student[40000];
int school[110][40000];//学校，最多110所，每所最多录取40000个学生
int tmp[40000];
bool cmp(person a,person b){
	if(a.avg!=b.avg) return a.avg>b.avg;
	else return a.ge>b.ge;
}
int main()
{
	//init
	for(int i=0;i<40000;i++){
		student[i].received=-1;
	} 

	int n,m,k;//申请者总数，学校数，志愿数
	scanf("%d%d%d",&n,&m,&k);//第一行
	
	for(int i=0;i<m;i++){//输入每个学校录取人数放在每行行首
		scanf("%d",&school[i][0]);
		school[i][1]=2;//录取指针
	}
	//输入
	for(int i=0;i<n;i++){
		scanf("%d%d",&student[i].ge,&student[i].gi);
		for(int j=0;j<k;j++){
			scanf("%d",&student[i].zhiyuan[j]);
		}
		student[i].avg=(student[i].ge+student[i].gi)/2;
		student[i].id=i;
	}
	//排序
	sort(student,student+n,cmp);
	//排名...........
	student[0].rank=1;
	for(int i=1;i<n;i++){
		if(student[i].avg<student[i-1].avg){
			student[i].rank=i+1;
		}else if(student[i].ge>student[i-1].ge){////否则比较ge
			student[i].rank=i+1;
		}else {//否则都相等的话
			student[i].rank=student[i-1].rank;
		}
	}
	//录取
	int zy0=student[0].zhiyuan[0];
	school[zy0][ school[zy0][1]++]=0;
	student[0].received=0;
	school[zy0][0]--;
	for(int i=1;i<n;i++){
		//首先判断是否与上一名的排名相同，不相同，则处理自己的就行
		if(student[i].rank!=student[i-1].rank){
			int p1=0;
			for(p1;p1<k;p1++){//指向该名学生的志愿
				int zy1=student[i].zhiyuan[p1];//zhiyuan
				if(school[zy1][0]>0){//若有剩余名额
					school[zy1][ school[zy1][1]++ ]=student[i].id;//i号学生被录取
					student[i].received=p1;
					school[zy1][0]--;
					break;//!!!!!!!!!!!!!!!!!!!!!!!
				}//否则自动下一志愿 
			}
		}
		//相同的话，则作特殊处理!!!!!!!!!!!!!!!!
		else{
			int p2=0;
			for(p2;p2<k;p2++){
				//如果与上一名学生的录取志愿不是同一位置
				if(student[i-1].received!=p2){
					int zy2=student[i].zhiyuan[p2];
					if(school[zy2][0]>0){
						school[zy2][ school[zy2][1]++ ]=student[i].id;
						student[i].received=p2;
						school[zy2][0]--;
						break;//!!!!!!!!
					}
				}//if
				//如果是
				else{
					int zy3=student[i].zhiyuan[p2];
					if(zy3==student[i-1].zhiyuan[ student[i-1].received ]){//同一位置，若再相等的话
						//则如果上一个人在此志愿被录取，那么我一定被录取
						school[zy3][ school[zy3][1]++ ]=student[i].id;//luqu
						if(school[zy3][0]>0) school[zy3][0]--; 
						break;
					}else{//不相等的话
						if(school[zy3][0]>0){
							school[zy3][ school[zy3][1]++ ]=student[i].id;
							student[i].received=p2;
							school[zy3][0]--;
							break;//!!!!!!!!
						}
					}
				}//else
			}
		}//else
		
	}//for
	//打印结果............
	for(int i=0;i<m;i++){
		int pt=0;
		for(int j=2;j<school[i][1];j++){
			tmp[pt++]=school[i][j];
		}
		sort(tmp,tmp+pt);
		if(pt>0){
			printf("%d",tmp[0]);
			for(int x=1;x<pt;x++)
				printf(" %d",tmp[x]);	
		}
		printf("\n");
	}

	return 0;
}

