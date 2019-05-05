class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    int l1 = 0, r1 = nums.size()-1, mid1;
    int l2 = 0, r2 = nums.size()-1, mid2;
    while (l1 <= r1) {
      mid1 = (l1 + r1) / 2;
      if (nums[mid1] == target&& (mid1 == 0 || nums[mid1 - 1] != target)) {
        res.push_back(mid1);
                break;
      }
      else if (nums[mid1] >= target) {
        r1 = mid1 - 1;
      }
      else {
        l1 = mid1 + 1;
      }
    }
        //cout<<"#######"<<endl;
    if (res.size() == 0) res.push_back(-1);
    while (l2 <= r2) {
      mid2 = (l2 + r2) / 2;
      if (nums[mid2] == target && (mid2==nums.size()-1||nums[mid2 + 1] != target)) {
        res.push_back(mid2);
                break;
      }
      else if (nums[mid2] > target) {
        r2 = mid2 - 1;
      }
      else {
        l2 = mid2 + 1;
      }
    }
        //cout<<"#######"<<endl;
    if (res.size() == 1) res.push_back(-1);

    return res;
  }
};

