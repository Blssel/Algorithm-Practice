// A1061orB1014.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
char week[8][6]={{},{"MON"},{"TUE"},{"WED"},{"THU"},{"FRI"},{"SAT"},{"SUN"}};
int main()
{

	char first1[70];
	char first2[70];
	char sec1[70];
	char sec2[70];
	gets(first1);
	gets(first2);
	gets(sec1);
	gets(sec2);
	int p = 0;
	while(p<70){
		if(first1[p]==first2[p]&&first1[p]>='A'&&first2[p]<='G'){
			printf("%s ",week[first1[p]-'A'+1]);
			p++;
			break;
		}
		p++;
	}
	while(p<70){
		if(first1[p]==first2[p]){
			if(first1[p]>='0'&&first1[p]<='9'){
				printf("0%c:",first1[p]);
				p++;
				break;
			}
			if(first1[p]>='A'&&first1[p]<='N'){
				printf("%d:",first1[p]-'A'+10);
				p++;
				break;
			}
		}
		p++;
	}
	/*    
	int q=0,loc1=1;int r=0,loc2=1;
	while(q<70&&r<70){
		if(!((sec1[q]>='a'&&sec1[q]<='z')||(sec1[q]>='A'&&sec1[q]<='Z'))){
			q++;
			continue;
		}
		if(!((sec2[r]>='a'&&sec2[r]<='z')||(sec2[r]>='A'&&sec2[r]<='Z'))){
			r++;
			continue;
		}
		if(sec1[q]==sec2[r]){
			printf("%02d\n",loc1);
			break;
		}else{
			q++;loc1++;
			r++;loc2++;
		}
	}
	*/
	int q=0;
	while(q<70){
		if((sec1[q]==sec2[q])&&((sec1[q]>='a'&&sec1[q]<='z')||(sec1[q]>='A'&&sec1[q]<='Z'))){
			printf("%02d\n",q);
			break;
		}else{
			q++;
		}
	}
	return 0;
}
