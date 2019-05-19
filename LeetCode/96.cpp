class Solution {
public:
  int helper(int begin, int end, vector<int>& dp) {
        if(dp[end-begin+1] != -1){
            return dp[end-begin+1];
        }
    if (end <= begin) return 1;
    int res = 0;
    for (int i = begin; i <= end; i++) {
      res += helper(begin, i - 1, dp) * helper(i + 1, end, dp);
    }
        dp[end-begin+1] = res;
    return res;
  }
  int numTrees(int n) {
        vector<int> dp(n+1, -1);
    return helper(1, n, dp);
  }
};
