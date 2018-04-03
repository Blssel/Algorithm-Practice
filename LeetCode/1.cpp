// 1cpp.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


int* twosum(int* nums, int numsSize, int target) {
  int* ans = (int *)malloc(2 * sizeof(int));
  for (int i = 0; i < numsSize - 1; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (nums[i] + nums[j] == target) {
        ans[0] = i;
        ans[1] = j;
        return ans;
      }
    }
  }
  return;
}
      
int main()
{
	int nums[1000] = {0};
	int target;
	int numsSize;
	scanf("%d%d", &target,&numsSize);
	for (int i = 0; i < numsSize; i++) {
		scanf("%d", &nums[i]);
	}
	int* ans = twosum(nums, numsSize, target);
	printf("%d %d\n", ans[0], ans[1]);
    return 0;
}