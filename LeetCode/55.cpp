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



// 改用贪心，题目还要好好琢磨
class Solution {
public:

  bool canJump(vector<int>& nums) {
    int begin = 0;
    int farthest = 0;
    while (true) {
            //cout<<"###"<<endl;
      int farthest_ = farthest;
      for (int i = begin; i <= farthest; i++) {
        farthest_ = max(farthest_, i + nums[i]);
                //cout<<farthest_<<endl;
        if (farthest_ >= nums.size()-1) return true;
      }
      if (farthest_ == farthest) return false;
      else {
        begin = farthest + 1;
        farthest = farthest_;
      }
    }
  }
};
