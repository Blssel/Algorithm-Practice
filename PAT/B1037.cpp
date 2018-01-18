// B1037.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
bool isSmaller(int g1, int s1, int k1, int g2, int s2, int k2){
	if (g1 != g2) return g1 < g2;
	else if (s1 != s2) return s1 < s2;
	else return k1 < k2;
}
void cha(int g1, int s1, int k1, int g2, int s2, int k2, int &g3, int &s3, int &k3){
	if (k1>=k2)
		k3 = k1 - k2;
	else{
		s1--;
		k3 = k1 + 29 - k2;
	}
	if (s1 >= s2)
		s3 = s1 - s2;
	else{
		g1--;
		s3 = s1 + 17 - s2;
	}
	g3 = g1 - g2;
}
int main()
{
	int g1, s1, k1,   g2, s2, k2,   g3 = 0, s3 = 0, k3 = 0;
	scanf("%d.%d.%d%d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	if (isSmaller(g2, s2, k2, g1, s1, k1)){
		cha(g1, s1, k1, g2, s2, k2, g3, s3, k3);
		g3 = 0 - g3;
		printf("%d.%d.%d\n", g3, s3, k3);
	}
		
	else{
		cha(g2, s2, k2, g1, s1, k1, g3, s3, k3);
		printf("%d.%d.%d\n", g3, s3, k3);
	}
		
	return 0;
}

