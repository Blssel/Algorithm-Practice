class Solution {
public:
  void helper(vector<int>& candidates, int target, int start, vector<vector<int>> res, vector<int> trace) {
    if (target == 0) {
      res.push_back(trace);
      return;
    }
    if (target < 0) return;
    for (int i = start; i < res.size(); i++) {
      trace.push_back(candidates[i]);
      helper(candidates, i, target - candidates[i], res, trace);
      trace.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> trace;
    helper(candidates, target, 0, res, trace);
    return res;
  }
};
