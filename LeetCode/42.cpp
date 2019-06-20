class Solution {
public:
  void helper(vector<int>& height, int begin, int end, int& res) {
    if (end - begin < 2) {
      return;
    }

    int max1=INT_MIN, index1, max2=INT_MIN, index2;
    for (int i = begin; i <= end; i++) {
      if (height[i] > max1) {
        max1 = height[i];
        index1 = i;
      }
    }
    for (int i = begin; i <= end; i++) {
      if (height[i] > max2 && i != index1) {
        max2 = height[i];
        index2 = i;
      }
    }
        int left = min(index1, index2);
        int right = max(index1, index2);
    if (right - left < 2) {
            helper(height, begin, left, res);
        helper(height, right, end, res);
      return;
    }
    else {
      int threshold = min(max1, max2);
      for (int i = left; i <= right; i++) {
        res += max(0, threshold - height[i]);
      }
            helper(height, begin, left, res);
        helper(height, right, end, res);
    }
  }
  int trap(vector<int>& height) {
    int res = 0;
    helper(height, 0, height.size() - 1, res);
    return res;
  }
};
