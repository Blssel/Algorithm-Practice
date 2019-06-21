class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //看能不能插入最后
    if (intervals.size() == 0 || newInterval[0] > intervals[intervals.size() - 1][1]) {
      intervals.insert(intervals.end(), newInterval);
    }
    int index;
    vector<int> del;
    for (int i = 0; i < intervals.size(); i++) {
      if ((newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]) ||
        (newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) ||
        (newInterval[0] < intervals[i][0] && newInterval[1] > intervals[i][1])) {
        intervals[i][0] = min(newInterval[0], intervals[i][0]);
        intervals[i][1] = max(newInterval[1], intervals[i][1]);

        for (int j = i + 1; j < intervals.size(); j++) {
          if (intervals[i][1] < intervals[j][0]) {
            break;
          }
          else {
            intervals[i][1] = max(intervals[i][1], intervals[j][1]);
            del.push_back(j); //记录删除j节点
          }
        }
        for (int k = 0; k<del.size(); k++) {
          cout << del[k] << " ";
        }
        if (del.size()>0) {
          intervals.erase(intervals.begin() + del[0], intervals.begin() + del[del.size() - 1] + 1);
        }
        break;
      }
      else if(newInterval[1]<intervals[i][0]) { //如果不重叠，则看是不是可以插入到缝隙中
        intervals.insert(intervals.begin() + i, newInterval);
        break;
      }
    }
    return intervals;
  }
};
