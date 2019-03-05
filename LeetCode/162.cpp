class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        for(int i=0;i<len-1;i++){
            if(nums[i]>nums[i+1])
                return i;
        }
        return len-1;
    }
};

// binary search(iterative)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int left=0,right=len-1;
        while(left!=right){
            int mid = (right+left)/2;
            if(nums[mid]>nums[mid+1]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};

// binary search(recursive)
class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right){
        if(left==right)
            return left;
        else{
            int mid = (left+right)/2;
            if(nums[mid]<nums[mid+1]){
                left = mid+1;
                return binarySearch(nums, left, right);
            }
            else{
                right = mid;
                return binarySearch(nums, left, right);
            }
        }
    }

    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size()-1);
    }
};
