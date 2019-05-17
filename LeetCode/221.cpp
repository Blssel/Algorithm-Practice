class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1));
    int res = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (matrix[i][j] == '0') {
          dp[i][j] = 0;
          res = max(res, 0);
          continue;
        }
        else {
          if (i - 1 < 0 || j - 1 < 0 || dp[i - 1][j - 1] == 0) {
            dp[i][j] = 1;
            res = max(res, 1);
            continue;
          }
          else {
            int left = 0, up = 0;
            for (int k = i; k >= i - dp[i - 1][j - 1]; k--) {
              if (matrix[k][j] == '1') {
                up++;
              }
              else {
                break;
              }
            }
            for (int k = j; k >= j - dp[i - 1][j - 1]; k--) {
              if (matrix[i][k] == '1') {
                left++;
              }
              else {
                break;
              }
            }
            int edge_len = min(left, up);
            dp[i][j] = edge_len;
            res = max(res, edge_len);
          }
        }
      }
    }
    //for (int i = 0; i<rows; i++) {
    //  for (int j = 0; j<cols; j++) {
    //    cout << dp[i][j] << " ";
    //  }
    //  cout << endl;
    //}
    return res*res;
  }
};
