class Solution {
public:
  void helper(string s, int left, int right, const int& n, vector<string>& res) {
    if (s.length() == 2 * n) {
      res.push_back(s);
      return;
    }
    if (left > 0) {
      helper(s + "(", left - 1, right, n, res);
    }
    if (right > left) {
      helper(s + ")", left, right - 1, n, res);
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> res;
    helper("", n, n, n, res);
    return res;
  }
};
