class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; i++) {
      vector<int> line;
      for (int j = 0; j < i + 1; j++) {
        if (j == 0 || j == i) {
          line.push_back(1);
        }
        else {
          line.push_back(res[res.size() - 1][j] + res[res.size() - 1][j - 1]);
        }
      }
      res.push_back(line);
    }
    return res;
  }
};
