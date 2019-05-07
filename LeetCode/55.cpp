class Solution {
public:
  bool helper(vector<int>& nums, int p, vector<int>& dp) {
    if (dp[p] != -1) return dp[p] == 1 ? true : false;
    if (p + nums[p] >= nums.size() - 1) {
      dp[p] = 1;
      return true;
    }
    if (nums[p] == 0) {
      dp[p] = 0;
      return false;
    }
    bool res = false;
    for (int i = nums[p]; i >= 1; i++) {
      res = res || helper(nums, p + i, dp);
    }
    dp[p] = res? 1:0;
    return res;
  }
  bool canJump(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return helper(nums, 0, dp);
  }
};
