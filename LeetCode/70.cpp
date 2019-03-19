class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 1;
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i] = -1;
        int res = helper(n, dp);
        return res;
    }
    int helper(int n, int dp[]){
        if(dp[n-1]!=-1) return dp[n-1];
        if(n==1 || n==2){
            dp[n-1] = n;
            return n;
        }
        else{
            int ways = helper(n-1,dp) + helper(n-2,dp);
            dp[n-1] = ways;
            return ways;
        }
    }
};

