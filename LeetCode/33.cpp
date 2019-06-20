class Solution {
public:
  int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
    string side_target, side_mid;
    if (target >= nums[0]) {
      side_target = "left";
    }
    else {
      side_target = "right";
    }
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] >= nums[0]) {
        side_mid = "left";
      }
      else {
        side_mid = "right";
      }
      if (side_target == side_mid) { //如果在同一侧，则和二分一样
        if (nums[mid] == target) {
          return mid;
        }
        else if (target < nums[mid]) {
          right = mid - 1;
        }
        else {
          left = mid + 1;
        }
      }
      else {
        if (side_target == "right") {
          left = mid + 1;
        }
        else {
          right = mid - 1;
        }
      }
    }
    return -1;
  }
};
