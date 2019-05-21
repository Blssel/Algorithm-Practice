class Solution {
public:
  int maxMoney(vector<int>& nums, int begin, int end, vector<int>& dp) {
    if (begin > end) return 0;
    if (dp[begin] != -1) return dp[begin];
    int rob = nums[begin] + maxMoney(nums, begin + 2, end, dp);
    int not_rob = maxMoney(nums, begin + 1, end, dp);
    int max_money = max(rob, not_rob);
    dp[begin] = max_money;
    return max_money;
  }
  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    vector<int> dp1(nums.size(), -1);
    vector<int> dp2(nums.size(), -1);
    return max(nums[0] + maxMoney(nums, 2, nums.size()-2, dp1), maxMoney(nums, 1, nums.size() - 1, dp2));
  }
};
