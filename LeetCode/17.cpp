class Solution {
public:
  void helper(string& digits, vector<string>& res, int k, string zuhe, map<int, string>& m) {
    if (k == digits.size()) res.push_back(zuhe);
    for (int i = 0; i < m[digits[k]-'0'].size(); i++) {
      helper(digits, res, k + 1, zuhe + m[digits[k] - '0'].substr(i,1), m);
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.size() == 0) return res;
    map<int, string> m = { { 2, "abc" },
    { 3, "def" },
    { 4, "ghi" },
    { 5, "jkl" },
    { 6, "nmo" },
    { 7, "pqrs" },
    { 8, "tuv" },
    { 9, "wxyz" } };
    helper(digits, res, 0, "", m);
    return res;
  }
};
