// 3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include <algorithm>

int lengthOfLongestSubstring(char* s) {
  int strLen = strlen(s);//字符串长度
  if (strLen == 0) return 0;
  int maxlen = 1;
  int curlen = 0;
  //定义并初始化标记数组，标记正在判断的子串中，某个字符是否出现过（值为-1代表未出现过，否则代表出现的位置）
  int apploc[128];
  for (int i = 0; i < 128; i++) {
    apploc[i]=-1;
  }
  int begin = 0;
  int stop_loc = -1;
  while ((strLen - begin) > maxlen) {
    for (int i = begin+curlen; i < strLen; i++) {
      if (apploc[s[i]] == -1) {
        apploc[s[i]] = i;
        curlen++;
        stop_loc = i; //标记i最终停在哪
      }
      else {
        int last_begin = begin;
        begin = apploc[s[i]] + 1;
        //需要清空截断面之前的标记
        for (int k = last_begin; k <= apploc[s[i]]; k++) {
          apploc[s[k]] = -1;
        }
        if (maxlen < curlen)
          maxlen = curlen;
        curlen = i - begin;
        break;
      }
    }
    if (stop_loc == (strLen - 1)) {
      if (maxlen < curlen)
        maxlen = curlen;
      break;
    }
  }
  return maxlen;
}



int main()
{
  char* s = "pwwkew";
  printf("%d\n",lengthOfLongestSubstring(s));
  return 0;
}

