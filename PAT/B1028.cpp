// B1028.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<string.h>
struct person{
	char name[10];
	int year;
	int month;
	int date;
}tmp,max_age,min_age;
bool overBroder(int year, int month, int date){
	if (year < 1814) return true;
	else if (year == 1814){
		if (month < 9) return true;
		else if (month == 9){
			if (date < 6) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}
bool underBorder(int year, int month, int date){
	if (year>2014) return true;
	else if (year == 2014){
		if (month > 9) return true;
		else if (month == 9){
			if (date > 6) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}
bool olderThanpresent(int year1, int month1, int date1, int year2, int month2, int date2){
	if (year1 < year2) return true;
	else if (year1 == year2){
		if (month1 < month2) return true;
		else if (month1 == month2){
			if (date1 < date2) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

int main()
{
	int n; int count = 0;
	max_age.year = 2014; max_age.month = 9; max_age.date = 7;//初始化最大最小年龄
	min_age.year = 1814; min_age.month = 9; min_age.date = 5;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s%d/%d/%d", tmp.name, &tmp.year, &tmp.month, &tmp.date);
		if (overBroder(tmp.year, tmp.month, tmp.date) || underBorder(tmp.year, tmp.month, tmp.date))
			continue;
		count++;
		if (olderThanpresent(tmp.year, tmp.month, tmp.date, max_age.year, max_age.month, max_age.date)){
			strcpy(max_age.name,tmp.name);
			max_age.year = tmp.year;
			max_age.month = tmp.month;
			max_age.date = tmp.date;
		}
		if (!olderThanpresent(tmp.year, tmp.month, tmp.date, min_age.year, min_age.month, min_age.date)){
			strcpy(min_age.name, tmp.name);
			min_age.year = tmp.year;
			min_age.month = tmp.month;
			min_age.date = tmp.date;
		}
	}
	if (count == 0) printf("%d", count);
	else
		printf("%d %s %s\n", count, max_age.name, min_age.name);
	
	return 0;
}
