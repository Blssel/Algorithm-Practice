// B1018.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<cstdio>
int winGesture(int x[]){
	int max = 0;
	for (int i = 0; i < 3; i++){
		if (x[i]>x[max]){
			max = i;
		}
	}
	return max;
}
int judge(char a, char b){
	if (a == 'B'){
		switch (b){
		case 'B':
			return 0;
			break;
		case 'C':
			return 1;
			break;
		case 'J':
			return 2;
			break;
		}
	}
	if (a == 'C'){
		switch (b){
		case 'B':
			return 2;
			break;
		case 'C':
			return 0;
			break;
		case 'J':
			return 1;
			break;
		}
	}
	if (a == 'J'){
		switch (b){
		case 'B':
			return 1;
			break;
		case 'C':
			return 2;
			break;
		case 'J':
			return 0;
			break;
		}
	}
}	
int main()
{
	int awin = 0; int alose = 0; 
	int bwin = 0; int blose = 0;
	int p = 0;
	int a[3] = { 0 }; int b[3] = { 0 };//0.1.2分别代表布（B），锤子(C)，剪刀(J)
	char win_gesture_a; char win_gesture_b;
	int n=1;
	char gesture_a; char gesture_b;
	scanf("%d", &n);
	
	while (n--){
		getchar();
		gesture_a = getchar();
		getchar();
		gesture_b = getchar();
		//printf("%c\n", gesture_a);
		//printf("%c\n", gesture_b);
		if (judge(gesture_a, gesture_b) == 0){
			p++;
		}
		else if (judge(gesture_a, gesture_b) == 1){
			awin++; blose++;
			if (gesture_a == 'B') a[0]++;
			else if (gesture_a == 'C') a[1]++;
			else a[2]++;
		}
		else{
			bwin++; alose++;
			if (gesture_b == 'B') b[0]++;
			else if (gesture_b == 'C') b[1]++;
			else b[2]++;
		}
	}
	
	if (winGesture(a) == 0) win_gesture_a = 'B';
	else if (winGesture(a) == 1) win_gesture_a = 'C';
	else win_gesture_a = 'J';
	
	if (winGesture(b) == 0) win_gesture_b = 'B';
	else if (winGesture(b) == 1) win_gesture_b = 'C';
	else win_gesture_b = 'J';
	printf("%d %d %d\n", awin, p, alose);
	printf("%d %d %d\n", bwin, p, blose);
	printf("%c %c\n", win_gesture_a, win_gesture_b);
	return 0;
}

