// A1033.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
using namespace std;
struct stion{
	double unit_price;
	double distance;
}station[510];
bool cmp(stion a,stion b){
	return a.distance <b.distance ; 
}
int main()
{
	double cmax,d,d_avg;
	int n;//����������յ���룬ÿ��λgas�ܵľ��룬��վ����
	scanf("%lf%lf%lf%d",&cmax,&d,&d_avg,&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&station[i].unit_price,&station[i].distance);
	}
	station[n].distance =d;
	station[n].unit_price =0;
	//
	sort(station,station+n+1,cmp);
	//
	bool can_arrived=true;
	double rmd_oil=0;
	int p=0;
	double bczy=cmax*d_avg;//������Զ
	double total=0;
	//
	if(station[0].distance>0) printf("The maximum travel distance = 0.00");
	//else if(bczy < (double)(d-station[n-1].distance )) printf("The maximum travel distance = %.2lf",station[n-1].distance );
	else{
		while(p<n){
			int q=p+1;//ָ�򱾴���Զ�������±�dexiayige
			if((station[q].distance-station[p].distance)>bczy){
				can_arrived=false;//���ܵ����յ�
				printf("The maximum travel distance = %.2lf",station[p].distance+bczy );
				break;
			} 
			while(station[q].distance-station[p].distance<=bczy&&q<=n){//��λq
				q++;
			}	
			//
			int k=p;
			for(int i=p+1;i<=q-1;i++){
				if(station[i].unit_price <=station[k].unit_price ){
					k=i;
					break;
				}
			}//for
			if(k==p){//˵��û�б���С�ģ��Ǿ�ѡһ����С��
				k=p+1;
				for(int i=p+1;i<=q-1;i++){
					if(station[i].unit_price <=station[k].unit_price ){
						k=i;
					}
				}
			}
			if(station[k].unit_price <station[p].unit_price ){
				double need_oil1=(station[k].distance - station[p].distance)/d_avg;
				if(need_oil1>rmd_oil){
					total+=(need_oil1 - rmd_oil) * station[p].unit_price;
					rmd_oil=0;
					p=k;
				}else{
					rmd_oil=rmd_oil-need_oil1;
					p=k;
				}
			}else{
				double need_oil2=(station[k].distance - station[p].distance)/d_avg;
				total+=(cmax - rmd_oil) * station[p].unit_price;//����
				rmd_oil=cmax-need_oil2;
				p=k;
			}
		}//while
		//���
		if(can_arrived==true){
			//double need_oil3=(double)( d - station[p].distance)/(double)d_avg;
			//if(rmd_oil<need_oil3) total+=(need_oil3 - rmd_oil)*station[p].unit_price ;
			printf("%.2lf",total);
		}
	}//else
	return 0;
}

