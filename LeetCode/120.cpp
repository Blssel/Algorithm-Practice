class Solution {
public:
  int helper(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    if (dp[row][col] != -1) {
      return dp[row][col];
    }
    if (row == (triangle.size() - 1)) {
      return triangle[row][col];
    }
    int res = triangle[row][col] + min(helper(row + 1, col, triangle, dp), helper(row + 1, col + 1, triangle, dp));
    dp[row][col] = res;
    return res;
  }
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp = triangle;
    for (int i = 0; i < triangle.size(); i++) {
      for (int j = 0; j < triangle[i].size(); j++) {
        dp[i][j] = -1;
      }
    }
    return helper(0, 0, triangle, dp);
  }
};
