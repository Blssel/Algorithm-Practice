class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 3; i++) {
            if (nums[i] > 0) {
                break;
            }
            else if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            else {
                int target = 0 - nums[i];
                int p = i + 1, q = nums.size() - 1;
                while (p < q) {
                    if (nums[p] + nums[q] == target) {
                        vector<int> ele(3);
                        ele[0] = nums[i], ele[1] = nums[p], ele[2] = nums[q];
                        res.push_back(ele);
                        p++; q--;
                        while (p < nums.size() && nums[p] == nums[p-1]) {
                            p++;
                        }
                        while (q > i && nums[q] == nums[q+1]) {
                            q--;
                        }
                    }
                    else if (nums[p] + nums[q] > target) {
                        q--;
                    }
                    else {
                        p++;
                    }
                }
                
            }
        }
        return res;
    }
};
