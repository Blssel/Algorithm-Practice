// A1080.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int received;//Ϊ-1��ʾδ¼ȡ����������Ӧ
}student[40000];
int school[110][40000];//ѧУ�����110����ÿ�����¼ȡ40000��ѧ��
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

	int n,m,k;//������������ѧУ����־Ը��
	scanf("%d%d%d",&n,&m,&k);//��һ��
	
	for(int i=0;i<m;i++){//����ÿ��ѧУ¼ȡ��������ÿ������
		scanf("%d",&school[i][0]);
		school[i][1]=2;//¼ȡָ��
	}
	//����
	for(int i=0;i<n;i++){
		scanf("%d%d",&student[i].ge,&student[i].gi);
		for(int j=0;j<k;j++){
			scanf("%d",&student[i].zhiyuan[j]);
		}
		student[i].avg=(student[i].ge+student[i].gi)/2;
		student[i].id=i;
	}
	//����
	sort(student,student+n,cmp);
	//����...........
	student[0].rank=1;
	for(int i=1;i<n;i++){
		if(student[i].avg<student[i-1].avg){
			student[i].rank=i+1;
		}else if(student[i].ge>student[i-1].ge){////����Ƚ�ge
			student[i].rank=i+1;
		}else {//������ȵĻ�
			student[i].rank=student[i-1].rank;
		}
	}
	//¼ȡ
	int zy0=student[0].zhiyuan[0];
	school[zy0][ school[zy0][1]++]=0;
	student[0].received=0;
	school[zy0][0]--;
	for(int i=1;i<n;i++){
		//�����ж��Ƿ�����һ����������ͬ������ͬ�������Լ��ľ���
		if(student[i].rank!=student[i-1].rank){
			int p1=0;
			for(p1;p1<k;p1++){//ָ�����ѧ����־Ը
				int zy1=student[i].zhiyuan[p1];//zhiyuan
				if(school[zy1][0]>0){//����ʣ������
					school[zy1][ school[zy1][1]++ ]=student[i].id;//i��ѧ����¼ȡ
					student[i].received=p1;
					school[zy1][0]--;
					break;//!!!!!!!!!!!!!!!!!!!!!!!
				}//�����Զ���һ־Ը 
			}
		}
		//��ͬ�Ļ����������⴦��!!!!!!!!!!!!!!!!
		else{
			int p2=0;
			for(p2;p2<k;p2++){
				//�������һ��ѧ����¼ȡ־Ը����ͬһλ��
				if(student[i-1].received!=p2){
					int zy2=student[i].zhiyuan[p2];
					if(school[zy2][0]>0){
						school[zy2][ school[zy2][1]++ ]=student[i].id;
						student[i].received=p2;
						school[zy2][0]--;
						break;//!!!!!!!!
					}
				}//if
				//�����
				else{
					int zy3=student[i].zhiyuan[p2];
					if(zy3==student[i-1].zhiyuan[ student[i-1].received ]){//ͬһλ�ã�������ȵĻ�
						//�������һ�����ڴ�־Ը��¼ȡ����ô��һ����¼ȡ
						school[zy3][ school[zy3][1]++ ]=student[i].id;//luqu
						if(school[zy3][0]>0) school[zy3][0]--; 
						break;
					}else{//����ȵĻ�
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
	//��ӡ���............
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

