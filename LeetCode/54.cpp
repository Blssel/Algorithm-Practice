class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size();
    if (m == 0) return res;
    int n = matrix[0].size();
    cout << ceil(m / 2.0);
    for (int i = 0; i <= ceil(m / 2.0); i++) {
      for (int j = i; j < n -1 - i; j++) {
        res.push_back(matrix[i][j]);
      }
      for (int k = i; k < m - 1 - i; k++) {
        res.push_back(matrix[k][n - 1 - i]);
      }
      for (int j = n - 1 - i; j > i; j--) {
        res.push_back(matrix[m - 1 - i][j]);
      }
      for (int k = m - 1 - i; k > i; k--) {
        res.push_back(matrix[k][i]);
      }
    }
    if (m % 2 == 1 && n % 2 == 1) {
      res.push_back(matrix[n / 2][n / 2]);;
    }
    return res;
  }
};
