class Solution {
public:
  bool cmp(vector<int> x, vector<int>y) {
    return x[0] < y[0];
  }
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //按起点排序
    sort(intervals.begin(), intervals.end(), cmp);

    int p = 0;
    while (p < intervals.size() - 1) {
      if (intervals[p + 1][0] >= intervals[p][0] && intervals[p + 1][0] <= intervals[p][1]) {
        intervals[p][1] = max(intervals[p][1], intervals[p + 1][1]);
        intervals.erase(intervals.begin() + p + 1);
      }
      else {
        p++;
        continue;
      }
    }
    return intervals;
  }
};
