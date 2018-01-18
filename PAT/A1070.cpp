// A1070.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<algorithm>
using namespace std;

struct mooncake{
	int id;
	double weight;
	double price;
	double unit_price;
}storage[1010];
bool cmp(mooncake a,mooncake b){
	return a.unit_price>b.unit_price;
}
int main()
{
	int n;
	double d;
	scanf("%d%lf",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%lf",&storage[i].weight);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&storage[i].price);
		storage[i].unit_price=storage[i].price/storage[i].weight;
	}
	sort(storage,storage+n,cmp);
	int p=0;
	double profit=0;
	while(p<n){
		if(storage[p].weight<=d){
			profit+=storage[p].price;//先加利润
			d-=storage[p].weight;//再更新市场需求
			storage[p].weight=0;
			storage[p].price=0;
			p++;
		}else{
			profit+=d*(storage[p].unit_price);
			storage[p].weight-=d;
			storage[p].price=storage[p].weight*storage[p].unit_price;
			d=0;
			p++;
			//break;
		}
	}
	printf("%.2lf",profit);
	return 0;
}

