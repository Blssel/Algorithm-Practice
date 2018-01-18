// A1006.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<string.h>
struct user{
	char id[20];
	int hour, minute, second;
}tmp, earlyest, latest;
void init(){
	earlyest.hour = 23; latest.hour = 00;
	earlyest.minute = 59; latest.minute = 00;
	earlyest.second = 59; latest.second = 00;
}
bool moreEarly(user a, user b){
	if (a.hour != b.hour) return a.hour < b.hour;
	else if (a.minute != b.minute) return a.minute < b.minute;
	else if (a.second != b.second) return a.second < b.second;
}
bool moreLate(user a, user b){
	if (a.hour != b.hour) return a.hour > b.hour;
	else if (a.minute != b.minute) return a.minute > b.minute;
	else if (a.second != b.second) return a.second > b.second;
}
int main()
{
	init();
	int m;
	scanf("%d", &m);
	while (m--){
		scanf("%s %d:%d:%d", tmp.id, &tmp.hour, &tmp.minute, &tmp.second);
		if (moreEarly(tmp, earlyest)){
			strcpy(earlyest.id, tmp.id);
			earlyest.hour = tmp.hour;
			earlyest.minute = tmp.minute;
			earlyest.second = tmp.second;
		}
		scanf("%d:%d:%d", &tmp.hour, &tmp.minute, &tmp.second);
		if (moreLate(tmp, latest)){
			strcpy(latest.id, tmp.id);
			latest.hour = tmp.hour;
			latest.minute = tmp.minute;
			latest.second = tmp.second;
		}
	}
	printf("%s %s\n", earlyest.id, latest.id);
	return 0;
}

